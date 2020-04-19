#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    set<int> duplicated_set;
    for (int e: a) {
        if (duplicated_set.find(e) != duplicated_set.end()) {
            continue;
        }
        int b = e;
        while (b <= 1000000001 / 2) {
            b *= 2;
            if (binary_search(a.begin(), a.end(), b)) {
                duplicated_set.insert(b);
            }
        }
    }
    cout << n - duplicated_set.size() << endl;
    
    return 0;
}

