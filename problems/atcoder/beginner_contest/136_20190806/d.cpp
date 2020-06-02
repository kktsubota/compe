#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    vector<int> ans(s.length(), 0);
    
    int head = 0;
    int i = 1;
    while (i < s.length()) {
        // cout << i << endl;
        // s[i-1] == 'R' && 
        if (s[i] == 'L') {
            int j = head;
            for(; j < s.length(); j++) {
                if (j > i && s[j] == 'R') {
                    i = j;
                    head = i;
                    break;
                }
                if ((i - j) % 2 == 0) {
                    ans[i] += 1;
                } else {
                    ans[i - 1] += 1;
                }
            }
            if (j == s.length()) {
                break;
            }
        } else {
            i++;
        }
    }
    for (auto v: ans) {
        cout << v << " ";
    }
    cout << endl;    
    return 0;
}
