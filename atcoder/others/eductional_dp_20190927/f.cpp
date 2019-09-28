#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <utility>

typedef long long int LL;
using namespace std;

int main(int argc, char const *argv[]) {
    string s, t;
    cin >> s;
    cin >> t;
    vector<vector<int>> max_length(s.length() + 1, vector<int>(t.length() + 1));
    vector<vector<string>> max_string(s.length() + 1, vector<string>(t.length() + 1));
    for (int i = 0; i <= s.length(); i++) {
        for (int j = 0; j <= t.length(); j++) {
            if (i == 0) {
                max_length[i][j] = 0;
                max_string[i][j] = "";
                continue;
            }
            if (j == 0) {
                max_length[i][j] = 0;
                max_string[i][j] = "";
            } else {
                if (s[i-1] == t[j-1]) {
                    max_length[i][j] = max_length[i-1][j-1] + 1;
                    max_string[i][j] = max_string[i-1][j-1] + s[i-1];
                } else {
                    if (max_length[i-1][j] >= max_length[i][j-1]) {
                        max_length[i][j] = max_length[i-1][j];
                        max_string[i][j] = max_string[i-1][j];
                    } else {
                        max_length[i][j] = max_length[i][j-1];
                        max_string[i][j] = max_string[i][j-1];
                    }
                }
            }
        }
    }
    cout << max_length[s.length()][t.length()] << endl;
    cout << max_string[s.length()][t.length()] << endl;
    // int length = max_length[s.length()][t.length()];
    // int index;
    // for (int i = 0; i <= s.length(); i++) {
    //     if (max_length[i][t.length()] == length) {
    //         index = i;
    //         break;
    //     }
    // }
    // cout << s.substr(index - length, length) << endl;
    return 0;
}