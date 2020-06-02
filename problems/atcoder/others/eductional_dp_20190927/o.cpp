#include <vector>
#include <iostream>

using namespace std;

// ref: https://atcoder.jp/contests/dp/submissions/7981121

int main(int argc, char const *argv[]) {
    int MOD = 1000000007;
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(1 << N, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int mask = 0; mask < (1 << N); mask++) {
            if (__builtin_popcount(mask) != i) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (a[i-1][j] && (mask & (1 << j))) {
                    dp[i][mask] += dp[i - 1][mask ^ (1 << j)];
                    if (dp[i][mask] >= MOD) {
                        dp[i][mask] -= MOD;
                    }
                }
            }
        }
    }
    // for (int i = 0; i <= N; i++) {
    //     for (int mask = 0; mask < (1 << N); mask++) {
    //         cout << dp[i][mask] << ", ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][(1 << N) - 1] << endl;
    return 0;
}
