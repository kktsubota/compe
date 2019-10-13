#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

typedef long long int ll;

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // dp[i][offset]: use A[i:i+offset]
    vector<vector<ll>> dp(N, vector<ll>(N + 1, -1LL));
    vector<vector<ll>> costs(N, vector<ll>(N + 1, 0LL));

    // init
    for (int i = 0; i < N; i++) {
        dp[i][0] = 0LL;
        dp[i][1] = A[i];
    }
    // dp
    for (int offset = 2; offset <= N; offset++) {
        for (int i = 0; i <= (N - offset); i++) {
            // A[i:i+j] + A[i+j:i+offset]
            ll value;
            ll cost;
            for (int j = 1; j < offset; j++) {
                ll v = dp[i][j] + dp[i+j][offset-j];
                ll c = costs[i][j] + costs[i+j][offset-j] + v;
                if ((j == 1) || (cost > c)) {
                    value = v;
                    cost = c;
                }
            }
            dp[i][offset] = value;
            costs[i][offset] = cost;
        }
    }
    // cout << "dp" << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         cout << dp[i][j] << ", ";
    //     }
    //     cout << endl;
    // }
    // cout << "costs" << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         cout << costs[i][j] << ", ";
    //     }
    //     cout << endl;
    // }

    cout << costs[0][N] << endl;
    
    return 0;
}
