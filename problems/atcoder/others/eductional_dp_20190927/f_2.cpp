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
                } else {
                    if (max_length[i-1][j] >= max_length[i][j-1]) {
                        max_length[i][j] = max_length[i-1][j];
                    } else {
                        max_length[i][j] = max_length[i][j-1];
                    }
                }
            }
        }
    }
    int length = max_length[s.length()][t.length()];
    int s_index = s.length();
    int t_index = t.length();
    deque<int> index;
    while (max_length[s_index][t_index] != 0) {
        if (max_length[s_index][t_index] == max_length[s_index][t_index-1]) {
            t_index--;
        } else if (max_length[s_index][t_index] == max_length[s_index-1][t_index]) {
            s_index--;
            continue;
        } else if (max_length[s_index][t_index] == (max_length[s_index-1][t_index-1] + 1)) {
            index.push_front(s_index-1);
            s_index--;
            t_index--;
            continue;
        } else {
            // unexpected
        }
    }
    string ans;
    for (auto idx: index) {
        ans += s[idx];
    }
    cout << ans << endl;
    return 0;
}