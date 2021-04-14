#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll pow_ll(const ll x, const ll a) {
    if (a == 0LL) {
        return 1LL;
    } else {
        ll x_half = pow(x, a / 2LL);
        if (a % 2LL == 0LL) {
            return x_half * x_half;
        } else {
            return x_half * x_half * x;
        }
    }
}


unordered_map<char, ll> get_value_map(const string& s) {
    unordered_map<char, ll> value_map;
    for (size_t i = 0; i < s.length(); i++) {
        if (value_map.find(s[i]) == value_map.end()) {
            value_map[s[i]] = 0LL;
        }
        value_map[s[i]] += pow_ll(10LL, (ll) (s.length() - i - 1));
    }
    return value_map;
}


int _main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    string s = s1 + s2 + s3;
    unordered_map<char, ll> s1_map = get_value_map(s1);
    unordered_map<char, ll> s2_map = get_value_map(s2);
    unordered_map<char, ll> s3_map = get_value_map(s3);
    
    set<char> chars_set(s.begin(), s.end());
    vector<char> chars_vec(chars_set.begin(), chars_set.end());

    // from answer
    if (chars_vec.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    vector<ll> values = {0LL, 1LL, 2LL, 3LL, 4LL, 5LL, 6LL, 7LL, 8LL, 9LL};
    unordered_set<char> heads;
    heads.insert(s1[0]);
    heads.insert(s2[0]);
    heads.insert(s3[0]);

    // O (5) * 10P10 * 10 = O(50 * 10!)
    do {
        int n1 = 0LL;
        int n2 = 0LL;
        int n3 = 0LL;
        bool flag = false;
        // chars_vec[i] corresponds with values[i].
        for (size_t i = 0; i < chars_vec.size(); i++) {
            auto chara = chars_vec[i];
            // head is 0
            if (values[i] == 0LL && heads.find(chara) != heads.end()) {
                flag = true;
                break;
            }
            if (s1_map.find(chara) != s1_map.end()) {
                n1 += (ll) (values[i] * s1_map[chara]);
            }
            if (s2_map.find(chara) != s2_map.end()) {
                n2 += (ll) (values[i] * s2_map[chara]);
            }
            if (s3_map.find(chara) != s3_map.end()) {
                n3 += (ll) (values[i] * s3_map[chara]);
            }
        }
        if (flag) {
            continue;
        }
        if (n1 + n2 == n3 && n1 > 0LL && n2 > 0LL && n3 > 0LL) {
            cout << n1 << endl;
            cout << n2 << endl;
            cout << n3 << endl;
            // for (int i = 0; i < chars_vec.size(); i++) {
            //     cout << chars_vec[i] << ": " << values[i] << ", ";
            // }
            // cout << endl; 
            return 0;
        }
    } while(next_permutation(values.begin(), values.end()));

    cout << "UNSOLVABLE" << endl;
    return 0;
}