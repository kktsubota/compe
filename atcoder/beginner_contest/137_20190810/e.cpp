#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

vector<vector<int>> edge(2500);
vector<int> score_stamp(2500, -1000000000);
map<pair<int, int>, int> score;

void dfs(int node, vector<bool> visited) {
    vector<int> targets = edge[node];
    for (auto target: targets) {
        int sc = score[make_pair(node, target)];
        
        if (visited[target]) {
            // positive loop
            if ((score_stamp[node] + sc) > score_stamp[target]) {
                throw exception();
            } else {
                return;
            }
        }
        score_stamp[target] = max(score_stamp[target], score_stamp[node] + sc);
        visited[target] = true;
        dfs(target, visited);
    }
}

int main(int argc, char const *argv[]) {
    int n, m, p;
    cin >> n >> m >> p;
    n--;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edge[a].push_back(b);
        score[make_pair(a, b)] = c - p;
    }
    score_stamp[0] = 0;
    try {
        vector<bool> visited(2500, false);
        dfs(0, visited);
        cout << score_stamp[n] << endl;
    } catch (exception e) {
        cout << -1 << endl;
    }
    return 0;
}
