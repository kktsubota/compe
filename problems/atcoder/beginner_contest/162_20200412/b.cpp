#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    ll ans = 0LL;
    for (ll i = 1LL; i <= N; i++) {
        if (i % 3 != 0LL and i % 5 != 0LL) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}