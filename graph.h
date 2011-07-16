//http://www.spoj.pl/problems/GRAPHS11/

#ifndef _SPARSE_GRAPH_
#define _SPARSE_GRAPH_

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int src, dst, wt;
	Edge(int src = -1, int dst = -1, int wt = -1): src(src), dst(dst), wt(wt) {}
};
struct node {
    int v;
	int wt;
    node *next;
    node(int x, int wt, node *t): v(x), wt(wt), next(t) {}
};
typedef node* link;

class sparseGraph
{
	int edges, vertices;
	bool digraph;
	bool *visited;
    vector<link> adj;
	vector<int> edge_to;
public:
    sparseGraph(int v, bool digraph = false);
    int v() const;
    int e() const;
    bool directed() const;
    void insert(Edge e);
    void remove_internal_edge(int v, int w);
    void remove(Edge e);
	bool edge(int v, int w);
    void bfs();
	void display_path(string method);
	void dfs();
	void _dfs(int v, bool msg);
	void connected_components();
	void clear_visited();
	stack<int> *pathto(int v, int s);
};

sparseGraph::sparseGraph(int v, bool digraph):
vertices(v), digraph(digraph), edges(0), adj(v+1), edge_to(v+1)
{
	visited = new bool[v+1];
	for (int i = 0; i < v+1; i++)
		visited[i] = false;
	edge_to.assign(v+1, 0);
    adj.assign(v+1, 0);
}

int sparseGraph::v() const { return vertices; }
int sparseGraph::e() const { return edges; }
bool sparseGraph::directed() const { return digraph; }

// keep the list sorted
link insert_node(struct node *head, int dst, int wt)
{
	int ret = 0;
	struct node *tmp;
	struct node *cur = head;
	struct node *prev = NULL;

	while (cur) {
		if (dst < cur->v) {
			ret = 1;
			break;
		}
		prev = cur;
		cur = cur->next;
	}
	if (ret) {
		tmp = new node(dst, wt, cur);
	} else {
		tmp = new node(dst, wt, NULL);
	}
	if (prev) {
		prev->next = tmp;
		return head;
	} else {
		return tmp;
	}
}

// for the same node, ordered by target node
void sparseGraph::insert(Edge e)
{
	int src = e.src, dst = e.dst, wt = e.wt;
	adj[src] = insert_node(adj[src], dst, wt);
    if (!digraph) adj[dst] = insert_node(adj[dst], src, wt);
    edges++;
}

void sparseGraph::remove_internal_edge(int v, int w)
{
    node *cur = adj[v];
    node *prev = NULL; 
    while (cur) {
        if (cur->v == w) {
            if (prev) {
                prev->next = cur->next;
            } else {
                adj[v] = cur->next;
            }
            delete cur;
            break;
        }
        prev = cur;
        cur = cur->next;
    }
}

void sparseGraph::remove(Edge e)
{
	int v = e.src, w = e.dst;
    remove_internal_edge(v, w);
    if (!digraph)
        remove_internal_edge(w, v);
    edges--;
}

bool sparseGraph::edge(int v, int w)
{
	node *cur = adj[v];
    while (cur) {
        if (cur->v == w) {
			return true;
        }
        cur = cur->next;
    }
	return false;
}

void sparseGraph::bfs()
{
	queue<int> bfs_queue;

	cout << "BFS:" << endl;
	visited[1] = true;
	bfs_queue.push(1);
	while (!bfs_queue.empty()) {
		int v = bfs_queue.front();
		bfs_queue.pop();
		node *cur = adj[v];
		cout << v << " ";
		while (cur) {
			if (!visited[cur->v]) {
				visited[cur->v] = true;
				edge_to[cur->v] = v;
				bfs_queue.push(cur->v);
			}
			cur = cur->next;
		}
	}
	cout << endl << endl;
}

stack<int> *sparseGraph::pathto(int v, int s)
{
	stack<int> *path = new stack<int>();
	for (int x = v; x != s; x = edge_to[x])
		path->push(x);
	path->push(s);
	return path;
}

void sparseGraph::display_path(string method)
{
	cout << method << " Paths:" << endl;
	for (int i = 0; i < adj.size(); i++) {
		if (adj[i]) {
			stack<int> *path = pathto(i, 1);
			while (!path->empty()) {
				int num = path->top();
				path->pop();
				cout << num << " ";
			}
			cout << endl;
			delete path;
		}
	}
	cout << endl << endl;
}

void sparseGraph::_dfs(int v, bool msg)
{
	visited[v] = true;
	struct node *cur = adj[v];
	if (msg) {
		cout << v << " ";
	}
	while (cur) {
		if (!visited[cur->v]) {
			edge_to[cur->v] = v;
			_dfs(cur->v, msg);
		}
		cur = cur->next;
	}
}

void sparseGraph::dfs()
{
	clear_visited();
	_dfs(1, true);
	cout << endl << endl;
}

void sparseGraph::connected_components()
{
	int i = 1;
	int count = 0;

	while (count != this->v()) {
		clear_visited();
		_dfs(i, false);
		cout << "C" << i << ": ";
		for (int j = 0; j < adj.size(); j++) {
			if (visited[j]) {
				cout << j << " ";
				count++;
			}
		}
		i++;
		cout << endl;
	}
}

void sparseGraph::clear_visited()
{
	for (int i = 0; i < adj.size(); i++) {
		visited[i] = false;
	}
}

#endif

#if 0
// client example
#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    int directed;
    int v, e;
    
    cin >> directed;
    cin >> v >> e;
	cout << directed << endl;
    cout << v << " " << e << endl;
    sparseGraph *g = new sparseGraph(v, directed);
    for (int i = 0; i < e; i++) {
		Edge e;
        int start, end, weight;
        cin >> e.src >> e.dst >> e.wt;
		cout << e.src << " " << e.dst << " " << e.wt << endl;
        g->insert(e);
    }
	cout << endl;

    g->bfs();
	g->display_path("BFS");
    
	g->dfs();
	g->display_path("DFS");

	g->connected_components();

    return 0;
}
#endif