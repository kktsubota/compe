#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    int MOD = 1000000007;
    cin >> n >> m;
    vector<int> Ss(n);
    vector<int> Ts(m);

    for (int i = 0; i < n; i++) {
        cin >> Ss[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> Ts[j];
    }
    vector<vector<long long int>> dp(n+1, vector<long long int>(m+1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> indices;
        for (int j = 0; j < m; j++) {
            if (Ts[j] == Ss[i-1]) {
                indices.push_back(j);
            }
        }
        for (int j = 1; j <= m; j++) {
            // use S[:i], T[:j]
            // without using i
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;

            auto it_end = lower_bound(indices.begin(), indices.end(), j);
            // using i
            for (int k = 0; k < j; k++) {
                // #appearances in T[k:j]
                auto it_beg = lower_bound(indices.begin(), indices.end(), k);
                int count = (int) (it_end - it_beg);
                // cout << i << j << "(" << k << ", " << j << "): " << count << endl;

                if (k == 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k] * count) % MOD;
                } else {
                    dp[i][j] = (dp[i][j] + (dp[i - 1][k] - dp[i - 1][k-1]) * count) % MOD;
                }
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j];
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << endl;

    return 0;
}
