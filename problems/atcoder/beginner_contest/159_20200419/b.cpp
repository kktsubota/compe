#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool is_kaibun(string s) {
    // s[0] - s[8] (9) i = 0 - 3
    // s[0] - s[7] (8) i = 0 - 3
    for (int i = 0; i < (s.length() / 2); i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    if (is_kaibun(s) && is_kaibun(s.substr(0, (s.length() - 1) / 2)) && is_kaibun(s.substr((s.length() + 1) / 2, s.length() - (s.length() + 3) / 2 + 1))) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
