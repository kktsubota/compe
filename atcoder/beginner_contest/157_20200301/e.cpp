#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, q;
    string s;
    cin >> n >> s >> q;
    map<char, set<int>> char_index_dict;
    for (int i = 0; i < s.length(); i++) {
        char_index_dict[s[i]].insert(i);
    }
    vector<string> types(q), As(q), Bs(q);
    for (int i = 0; i < q; i++) {
        cin >> types[i] >> As[i] >> Bs[i];
    }    
    for (int i = 0; i < q; i++) {
        int type = stoi(types[i]);
        if (type == 1) {
            int a = stoi(As[i]) - 1;
            char b = Bs[i][0];
            if (s[a] != b) {
                char_index_dict[s[a]].erase(a);
                s[a] = b;
                char_index_dict[s[a]].insert(a);
            }
            // cout << s << endl;
        } else {
            int a = stoi(As[i]) - 1;
            int b = stoi(Bs[i]) - 1;

            int ans = 0;
            for (char c = 'a'; c <= 'z'; c++) {
                auto beg_ptr = char_index_dict[c].lower_bound(a);
                auto end_ptr = char_index_dict[c].lower_bound(b + 1);
                if (end_ptr == char_index_dict[c].end()) {
                    if (beg_ptr != char_index_dict[c].end()) {
                        ans += 1;
                    }
                } else {                    
                    if (*beg_ptr != *end_ptr) {
                        ans += 1;
                    }
                }
                // int beg = distance(char_index_dict[c].begin(), char_index_dict[c].lower_bound(a));
                // int end = distance(char_index_dict[c].begin(), char_index_dict[c].lower_bound(b + 1));
                // cout << a << b << c << ", " << beg << " - " << end << endl;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
