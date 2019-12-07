#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

typedef long long int ll;

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<int> dp(n + 1);
    // init
    if (s[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = (int) (s[i] - '0');
    }

    for (int i = 0; i <= n; i++) {
        if (dp[i] == -1) {
            continue;
        }
        // find dp[i] is min, and index is max; from [max(0, i - M), i - 1]
        int index = max(i - m, 0);
        if (dp[index] != -1) {
            dp[i] = dp[index] + 1;
        } else {
            int index_prev = index;
            index = (index + i) / 2
            while (true) {
                if (dp[index] != -1) {
                    dp[i] = max(dp[i], dp[index] + 1);
                }
                
            }
        }
    }

    return 0;
}
