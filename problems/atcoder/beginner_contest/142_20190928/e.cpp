#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int pow_int(int base, int k) {
    if (k == 0) {
        return 1;
    } else {
        return base * pow_int(base, k - 1);
    }
}
int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    
    int n_pow = pow_int(2, n);
    vector<int> nodes(n_pow);
    for (int i = 0; i < n_pow; i++) {
        nodes[i] = i;
    }
    vector<vector<int>> edges(n_pow);
    map<pair<int, int>, int> costs;
    vector<int> As;
    vector<int> keys;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int key = 0;
        for (int j = 0; j < b; j++) {
            int c;
            cin >> c;
            key += pow_int(2, c);
        }
        As.push_back(a);
        keys.push_back(key);
    }

    for (int i = 0; i < n_pow; i++) {
        for (int j = 0; j < m; j++) {
            int to = i & keys[j];
            edges[i].push_back(to);
            costs[make_pair(i, to)] = As[j];
        }
    }
    queue<int> que;
    que.push(0);
    
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        
        int index;
        int cost = INT32_MAX;
        for (auto to: edges[node]) {
            if (cost > costs[make_pair(node, to)]) {
                index = to;
                cost = costs[make_pair(node, to)];
            }
        }

    }


    return 0;
}
