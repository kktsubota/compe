#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> As(n - 1), Bs(n - 1);
    unordered_map<int, vector<int>> edge;
    for (int i = 0; i < n - 1; i++) {
        cin >> As[i] >> Bs[i];
        As[i] -= 1;
        Bs[i] -= 1;
        edge[As[i]].push_back(Bs[i]);
        edge[Bs[i]].push_back(As[i]);
    }
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        unordered_set<int> adj_colors;
        for (auto conn_1st: edge[i]) {
            adj_colors.insert(color[conn_1st]);
            for (auto conn_2nd: edge[conn_1st]) {
                adj_colors.insert(color[conn_2nd]);
            }
        }
        auto it = adj_colors.find(-1);
        if (it != adj_colors.end()) {
            adj_colors.erase(it);
        }
        color[i] = k - adj_colors.size();
    }
    long long int MOD = 1000000007LL;
    long long int ans = 1;
    for (auto c: color) {
        // cout << c << ", ";
        ans = (ans * c) % MOD;
    }
    // cout << endl;
    cout << ans << endl;
    return 0;    
}