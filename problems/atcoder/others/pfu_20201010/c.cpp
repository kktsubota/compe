#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    set<int> p_set;
    vector<int> p_vec;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        p_vec.push_back(v);
    }
    for (int v = 0; v <= (n + 1); v++) {
        p_set.insert(v);
    }

    for (int i = 0; i < n; i++) {
        int v = p_vec[i];
        p_set.erase(v);
        cout << *p_set.begin() << endl;
    }
    return 0;
}