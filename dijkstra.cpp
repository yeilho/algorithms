using namespace std;

struct Graph 
{
public:
    Graph(string name) : id(name) {}
    int distance = INT_MAX;
    string id;
    vector<pair<Graph*, int>> edges; // node id and distance from this node

};
struct Comp 
{
    bool operator()(const Graph* lhs, const Graph* rhs) const {
        return lhs->distance < rhs->distance;
    }
};

void dijkstra(Graph* s)
{
    s->distance = 0;
    set<Graph*, Comp> nodeSet; // heap does not have a good way of updating
    map<string, int> dist; // Graph also store the distance
    nodeSet.emplace(s);
    dist[s->id] = 0;

    while (!nodeSet.empty())
    {
        Graph* u = *nodeSet.cbegin();
        nodeSet.erase(nodeSet.cbegin());
        for (const auto& x : u->edges)
        {
            int v_distance = x.second + u->distance;
            if (v_distance < x.first->distance) {
                x.first->distance = v_distance;
                nodeSet.emplace(x.first);
                dist[x.first->id] = v_distance;
            }
        }
    }

    for (auto x : dist)
    {
        cout << "ID: " << x.first.c_str() << ", distance: " << x.second << endl;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    Graph s("S");
    Graph b("B");
    Graph c("C");
    Graph d("D");
    s.edges.push_back(make_pair(&b, 24));
    s.edges.push_back(make_pair(&d, 20));
    s.edges.push_back(make_pair(&c, 3));
    c.edges.push_back(make_pair(&d, 12));
    dijkstra(&s);

    return 0;
}
