#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char const *argv[]) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    long long int dp[41][2];
    for (int i = 0; i <= 40; i++) {
        long long int d = k >> (40 - i);
        k -= d << (40 - i);
        
        if (i == 0) {
            // assert d == 0;
            dp[i][0] = -1LL;
            dp[i][1] = 0LL;
            continue;
            // cout << d << ": " << dp[i][0] << ", " << dp[i][1] << endl;
        }
        long long int sum_i = 0;
        for (int j = 0; j < n; j++) {
            auto a = A[j];
            long long int d_a = a >> (40 - i);
            sum_i += d_a;
            A[j] -= d_a << (40 - i);
        }
        // small -> small
        if (dp[i-1][0] != -1) {
            auto temp = max(sum_i, n - sum_i) << (40 - i);
            dp[i][0] = dp[i-1][0] + temp;
        } else {
            dp[i][0] = -1;
        }
        if (d == 1) {
            // exact -> small by choosing 0
            auto temp = sum_i << (40 - i);
            dp[i][0] = max(dp[i][0], dp[i-1][1] + temp);
            // exact -> exact by choosing 1
            temp = (n - sum_i) << (40 - i);
            dp[i][1] = dp[i-1][1] + temp;
        } else {
            // exact -> exact by choosing 0
            auto temp = sum_i << (40 - i);
            dp[i][1] = dp[i-1][1] + temp;
        }
        // cout << d << ": " << dp[i][0] << ", " << dp[i][1] << endl;
    }
    cout << max(dp[40][0], dp[40][1]) << endl;
    return 0;
}
