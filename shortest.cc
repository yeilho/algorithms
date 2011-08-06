// Breadth First Search Algorithm

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define N 10
#define M 10
int map[N][M];
int bad[N][M];

// I did not use this but it could be useful 
// in the future so I added it here
vector <string> parse(string s)
{
    int i = 0, j;
    vector <string> ret;

    while (i != s.size()) {
        while (i != s.size() && isspace(s[i])) i++;
        if (i == s.size())
            break;
        j = i;
        while (j != s.size() && !isspace(s[j])) j++;
        ret.push_back(s.substr(i, j-i));
        i = j;
    }
    return ret;
}

int chk_border(int x)
{
    if (x < 0 || x >= N)
        return 0;
    return 1;
}

// for now, we always start (0,0)
int shortest(vector <string> forbid, int x, int y)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            map[i][j] = 1000;
    map[0][0] = 0;

    for (int i = 0; i < forbid.size(); i++) {
        for (int j = 0; j < forbid[i].size(); j++) {
            if (forbid[i][j] == 'x') {
                bad[i][j] = 1;
            }
            else
                bad[i][j] = 0;
        }
    }
    vector <int> vi(2);
    vi[0] = 0; vi[1] = 0;
    queue <vector<int> > q;
    q.push(vi);

    while (!q.empty()) {
        vi = q.front(); q.pop();
        int cur = map[vi[0]][vi[1]];
        int tv1 = vi[0];
        int tv2 = vi[1];

        vi[0] = (tv1 + 1);
        if (bad[vi[0]][vi[1]] != 1 &&
            map[vi[0]][vi[1]] == 1000 &&
            chk_border(vi[0]) != 0) {
            map[vi[0]][vi[1]] = cur + 1;
            q.push(vi);
        }
        vi[0] = tv1;
        vi[1] = (tv2 + 1);
        if (bad[vi[0]][vi[1]] != 1 &&
            map[vi[0]][vi[1]] == 1000 &&
            chk_border(vi[1]) != 0) {
            map[vi[0]][vi[1]] = cur + 1;
            q.push(vi);
        }
        vi[0] = tv1 - 1;
        vi[1] = tv2;
        if (bad[vi[0]][vi[1]] != 1 &&
            map[vi[0]][vi[1]] == 1000 &&
            chk_border(vi[0]) != 0) {
            map[vi[0]][vi[1]] = cur + 1;
            q.push(vi);
        }
        vi[0] = tv1;
        vi[1] = tv2 - 1;
        if (bad[vi[0]][vi[1]] != 1 &&
            map[vi[0]][vi[1]] == 1000 &&
            chk_border(vi[1]) != 0) {
            map[vi[0]][vi[1]] = cur + 1;
            q.push(vi);
        }
    }
    int ans = map[x][y];
    return ans < 1000 ? ans : -1;
}

int main(int argc, char *argv[])
{
    int x, y;
    string istr;
    vector <string> forbid;

    cin >> x >> y;
    while (getline(cin, istr)) {
        if (!istr.empty())
            forbid.push_back(istr);
    }
    cout << "Go to " << x << ", " << y << endl;
    int ans = shortest(forbid, x, y);
    cout << ans << endl;

    return 0;
}
