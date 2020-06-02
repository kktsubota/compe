#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int dp[3001][6001];

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    // i, t
    for (int i = 0; i < 3001; i++) {
        for (int j = 0; j < 6001; j++) {
            dp[i][j] = 0;
        }
    }
    int t_max = *max_element(A.begin(), A.end());
    for (int i = 0; i <= N; i++) {
        for (int t = 0; t <= (T + t_max); t++) {
            if (i == 0) {
                continue;
            }
            if ((t >= A[i-1]) && (dp[i-1][t] < (dp[i-1][t-A[i-1]] + B[i-1]))) {
                dp[i][t] = dp[i-1][t-A[i-1]] + B[i-1];
            } else {
                dp[i][t] = dp[i-1][t];
            }
        }
    }
    // for (int i = 0; i <= N; i++) {
    //     for (int t = 0; t <= T; t++) {
    //         cout << dp[i][t] << ", ";
    //     }
    //     cout << endl;
    // }
    int ans = -1;
    for (int t = T; t <= (T + t_max); t++) {
        // get max time element
        for (int i = N; i >= 1; i--) {
            if (dp[i][t] != dp[i-1][t]) {
                if ((t - A[i]) <= (T - 1)) {
                    ans = max(ans, dp[N][t]);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
