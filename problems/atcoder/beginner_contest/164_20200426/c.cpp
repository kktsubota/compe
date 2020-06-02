#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    set<string> string_set;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string_set.insert(s);
    }
    cout << string_set.size() << endl;
    return 0;
}