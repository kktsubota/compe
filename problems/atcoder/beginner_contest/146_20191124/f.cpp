#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

typedef long long int ll;

using namespace std;

// somewhat fails
int main(int argc, char const *argv[])
{
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<int> dp(n + 1);
    vector<int> dp_from(n + 1);
    vector<int> available;
    // init
    if (s[0] != '0' || s[n] != '0') {
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

    for (int i = 1; i <= n; i++) {
        if (dp[i] == -1) {
            continue;
        }
        // find dp[i] is min, and index is max; from [max(0, i - M), i - 1]
        int index = max(i - m, 0);
        auto it = lower_bound(available.begin(), available.end(), index);
        // not found in [max(i - m, 0), i)
        if (*it >= i || *it < index) {
            dp[i] = -1;
        } else {
            dp[i] = dp[*it] + 1;
            dp_from[i] = *it;
        }
    }
    if (dp[n] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> ans;
        int index = n;
        ans.push_back(index);
        while (true) {
            index = dp_from[index];
            ans.push_back(index);
            if (index == 0) {
                break;
            }
        }
        reverse(ans.begin(), ans.end());

        for (int i = 0; i < (ans.size() - 1); i++) {
            cout << ans[i + 1] - ans[i];
            if (i != ans.size() - 2) {
                 cout << " ";
            } else {
                cout << endl;
            }
        }
    }
    return 0;
}
