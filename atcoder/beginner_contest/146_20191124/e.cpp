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
    vector<int> available;
    // init
    if (s[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        // -1: game over, 0: no problem
        dp[i] = (int) (s[i] - '0');
        dp[i] = - dp[i];
        if (dp[i] == 0) {
            available.push_back(i);
        }
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
            auto it = lower_bound(available.begin(), available.end(), index);
            // not found
            if (*it >= i) {
                dp[i] = -1;
            } else {
                dp[i] = dp[*it] + 1;
            }
        }
    }

    return 0;
}
