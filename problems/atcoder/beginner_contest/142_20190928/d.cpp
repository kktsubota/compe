#include <iostream>
#include <vector>

typedef long long int ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (a > b) {
        return gcd(b, a);
    }
    // a <= b
    ll r = b % a;
    if (r == 0LL) {
        return a;
    } else {
        return gcd(r, a);
    }
}

vector<bool> is_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    int indicator = 2;
    while ((indicator * indicator) <= n) {
        if (!is_prime[indicator]) {
            indicator++;
            continue;
        }
        for (int i = 2; (i * indicator) <= n; i++) {
            is_prime[i * indicator] = false;
        }
        indicator++;
    }
    return is_prime;
}

int sqrt_int(ll n) {
        ll n_sqrt;
        // obtain sqrt
        for (n_sqrt = 1LL; n_sqrt < n; n_sqrt++) {
            if (n_sqrt * n_sqrt > n) {
                break;
            }
        }
        return (int) n_sqrt;
}
            
int main(int argc, char const *argv[])
{    
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    if (g == 1LL) {
        cout << 1 << endl;
        return 0;
    } else {
        // cout << g << endl;
        ll n = g;

        // primes of 1 - sqrt(n)
        int n_sqrt = sqrt_int(n);
        // cout << n_sqrt << endl;
        vector<bool> is_prime = is_primes(n_sqrt);

        // i == 1
        int ans = 1;
        bool flag = true;
        while (flag) {
            flag = false;
            for (ll p = 2LL; p <= (ll) n_sqrt; p++) {
                if (!is_prime[p]) {
                    continue;
                }
                if (n % p == 0LL) {
                    ans++;
                    while (n % p == 0) {
                        n = n / p;
                    }
                    flag = true;
                }
            }
        }
        if (n != 1LL) {
            // n is prime
            ans++;
        }
        cout << ans << endl;
        return 0;
    }
}
