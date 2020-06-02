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
    vector<vector<ll>> dp(N, vector<ll>(N + 1, -1));
    vector<vector<int>> index(N, vector<int>(N + 1, -1));

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
            int idx;
            for (int j = 1; j < offset; j++) {
                ll v = dp[i][j] + dp[i+j][offset-j];
                if ((j == 1) || (value > v)) {
                    value = v;
                    idx = j;
                }
            }
            dp[i][offset] = value;
            index[i][offset] = idx;
        }
    }
    cout << "dp" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            cout << dp[i][j] << ", ";
        }
        cout << endl;
    }
    cout << "index" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            cout << index[i][j] << ", ";
        }
        cout << endl;
    }

    // traverse
    ll ans = 0LL;

    queue<pair<int, int>> que;
    que.push(make_pair(0, N));
    while (!que.empty()) {
        pair<int, int> q = que.front();
        que.pop();
        if (q.second <= 1) {
            continue;
        } else {
            ans += dp[q.first][q.second];
            int idx = index[q.first][q.second];
            que.push(make_pair(q.first, idx));
            que.push(make_pair(q.first + idx, q.second - idx));
            cout << q.first << ", " << idx << ", " << q.second << endl;
        }        
    }
    cout << ans << endl;
    
    return 0;
}
