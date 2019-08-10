#include <iostream>

using namespace std;


long long int powmod(long long int n, long long int p, long long int m) {
    if (p == 0) {
        return 1;
    }
    long long int x_sqrt = powmod(n, p >> 1, m);
    long long int x = (x_sqrt * x_sqrt) % m;
    if (p & 1) {
        x = (x * n) % m;
    }
    return x;
}

int main() {
    long long int n, m, p;
    cin >> n >> m >> p;
    cout << powmod(n, p, m) << endl;
    return 0;
}