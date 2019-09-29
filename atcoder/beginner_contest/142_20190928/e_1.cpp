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
    vector<int> As;
    vector<int> keys;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int key = 0;
        for (int j = 0; j < b; j++) {
            int c;
            cin >> c;
            key += pow_int(2, c - 1);
        }
        As.push_back(a);
        keys.push_back(key);
    }
    cout << n_pow << endl;
    for (auto key: keys) {
        cout << key << ", ";
    }
    cout << endl;

    vector<vector<int>> costs(m + 1, vector<int>(n_pow));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n_pow; j++) {
            if (i == 0) {
                costs[i][j] = (j == 0) ? 0 : INT32_MAX;
                continue;
            }
            if (costs[i-1][j^keys[i-1]] == INT32_MAX) {
                costs[i][j] = costs[i-1][j];
            } else {
                // j = 111, key=110, j^key=001 (do not consider 011, 101)
                costs[i][j] = min(costs[i-1][j], costs[i-1][j^keys[i-1]] + As[i-1]);
            }
        }
        // I should have implemented with a distributional DP.
    }
    if (costs[m][n_pow - 1] == INT32_MAX) {
        cout << -1 << endl;
    } else {
        cout << costs[m][n_pow - 1] << endl;
    }
    return 0;
}
