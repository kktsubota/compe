#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, ans;
    string s;
    cin >> n;
    cin >> s;
    // 12
    // 6 -> 9 -> 10 -> 11
    int length = s.length() / 2;
    // [lower, upper)
    int lower = 0;
    int upper = s.length() / 2 + 1;
    while (true) {
        // cout << length << endl;
        bool having = false;
        set<string> string_set;
        for (int i = 0; i < s.length() - length; i++) {
            string subs = s.substr(i, length);
            // cout << subs << ", ";
            auto it = string_set.find(subs);
            if (it == string_set.end()) {
                string_set.insert(subs);
            } else {
                // X: implement rfind for set.
                // no multile elements
                auto rit = string_set.rfind(subs);
                if (distance(string_set.begin(), it) < (i - length) || distance(string_set.begin(), rit) > (i + length)) {
                    having = true;
                    break;
                } else {
                    string_set.insert(subs);
                }
            }
        }
        int new_length;
        // binary search
        if (having) {
            new_length = (length + upper) / 2;
            if (new_length == upper - 1) {
                ans = upper - 1;
                break;
            } else {
                lower = length;
                length = new_length;
            }
        } else {
            new_length = (lower + length) / 2;
            // cout << new_length << endl;
            if (new_length == lower) {
                ans = lower;
                break;
            } else {
                upper = length;
                length = new_length;
            }
        }
        // cout << "[" << lower << ", " << upper << ")" << "length: " << length << endl;
    }
    cout << ans << endl;
    return 0;
}
