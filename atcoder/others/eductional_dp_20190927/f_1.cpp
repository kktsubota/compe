#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <utility>
#include <queue>

typedef long long int LL;
using namespace std;

int main(int argc, char const *argv[]) {
    string s, t;
    cin >> s;
    cin >> t;
    vector<vector<int>> max_length(s.length() + 1, vector<int>(t.length() + 1));
    vector<vector<deque<int>>> max_index(s.length() + 1, vector<deque<int>>(t.length() + 1));
    for (int i = 0; i <= s.length(); i++) {
        for (int j = 0; j <= t.length(); j++) {
            if (i == 0) {
                max_length[i][j] = 0;
                continue;
            }
            if (j == 0) {
                max_length[i][j] = 0;
            } else {
                if (s[i-1] == t[j-1]) {
                    max_length[i][j] = max_length[i-1][j-1] + 1;
                    max_index[i][j] = max_index[i-1][j-1];
                    max_index[i][j].push_back(i-1);
                } else {
                    if (max_length[i-1][j] >= max_length[i][j-1]) {
                        max_length[i][j] = max_length[i-1][j];
                        max_index[i][j] = max_index[i-1][j];
                    } else {
                        max_length[i][j] = max_length[i][j-1];
                        max_index[i][j] = max_index[i][j-1];
                    }
                }
            }
        }
    }
    string ans;
    for (auto idx: max_index[s.length()][t.length()]) {
        ans += s[idx];
    }
    cout << ans << endl;
    return 0;
}