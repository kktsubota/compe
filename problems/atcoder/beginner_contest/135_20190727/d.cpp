#include <iostream>
#include <string>
#include <vector>
// #include <cxx-prettyprint/prettyprint.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    long long int MOD = 1000000000 + 7;
    string s;
    cin >> s;
    vector<vector<long long int>> dp(s.length(), vector<long long int>(13, 0));
    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            if (s[i] == '?') {
                for (int j = 0; j <=9; j++) {
                    dp[i][j] = 1LL;
                }
            } else {
                int j = (int) (s[i] - '0');
                dp[i][j] = 1LL;
            }
        } else {
            for (int j = 0; j < 13; j++) {
                if (s[i] == '?') {
                    for (int k = 0; k <= 9; k++) {
                        int j_now = (j * 10 + k) % 13;
                        dp[i][j_now] += dp[i - 1][j];
                        dp[i][j_now] %= MOD;
                    }
                } else {
                    int k = (int) (s[i] - '0');
                    int j_now = (j * 10 + k) % 13;
                    dp[i][j_now] += dp[i - 1][j];
                    dp[i][j_now] %= MOD;
                }
            }
        }
        // for (auto d: dp) {
        //     for (auto _: d) {
        //         cout << _ << ", ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    cout << dp[s.length() - 1][5] << endl;
    return 0;
}
