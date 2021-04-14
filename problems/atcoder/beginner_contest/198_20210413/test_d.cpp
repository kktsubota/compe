#include <bits/stdc++.h>
#include "d.h"

using namespace std;
typedef long long ll;


void print(unordered_map<char, ll> m) {
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        cout << iter->first << ": " << iter->second << ", ";
    }
    cout << endl;
}

int main() {
    ll x = 10LL;
    // 1
    cout << pow_ll(x, 0LL) << endl;
    // 10
    cout << pow_ll(x, 1LL) << endl;
    // 100
    cout << pow_ll(x, 2LL) << endl;
    // 1000
    cout << pow_ll(x, 3LL) << endl;
    unordered_map<char, ll> m = get_value_map("asda");    
    print(m);
    m = get_value_map("aaaa");
    print(m);
    m = get_value_map("a");
    print(m);
    m = get_value_map("aahifalfa");
    print(m);
    return 0;
}