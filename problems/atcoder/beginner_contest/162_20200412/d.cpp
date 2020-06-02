#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;


int main(int argc, char const *argv[]) {
    ll N;
    string S;
    cin >> N >> S;

    map<char, vector<ll>> count;
    for (int i = 0LL; i <= N; i++) {
        if (i == 0LL) {
            count['R'].push_back(0);
            count['G'].push_back(0);
            count['B'].push_back(0);
        } else {
            if (S[i - 1] == 'R') {
                count['R'].push_back(count['R'][i - 1] + 1LL);
                count['G'].push_back(count['G'][i - 1]);
                count['B'].push_back(count['B'][i - 1]);
            }
            else if (S[i - 1] == 'G') {
                count['R'].push_back(count['R'][i - 1]);
                count['G'].push_back(count['G'][i - 1] + 1LL);
                count['B'].push_back(count['B'][i - 1]);
            }
            if (S[i - 1] == 'B') {
                count['R'].push_back(count['R'][i - 1]);
                count['G'].push_back(count['G'][i - 1]);
                count['B'].push_back(count['B'][i - 1] + 1LL);
            }
        }
    }
    ll ans = 0LL;
    for (ll i = 0LL; i < N; i++) {
        for (ll k = i + 2; k < N; k++) {
            if (S[i] == S[k]) {
                continue;
            }
            char s;
            if ((S[i] == 'R' && S[k] == 'B') || (S[i] == 'B' && S[k] == 'R')) {
                s = 'G';
            } else if ((S[i] == 'R' && S[k] == 'G') || (S[i] == 'G' && S[k] == 'R')) {
                s = 'B';
            } else if ((S[i] == 'G' && S[k] == 'B') || (S[i] == 'B' && S[k] == 'G')) {
                s = 'R';
            }
            ll c = count[s][k + 1] - count[s][i];

            if ((i + k) % 2 == 0) {
                if (S[(i + k) / 2] == s) {
                    c -= 1LL;
                }
            }
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}