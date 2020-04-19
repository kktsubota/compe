#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
    // (m + n) C 2 - m C 1 * n C 1
    int m, n;
    cin >> m >> n;
    cout << (m + n) * (m + n - 1) / 2 - m * n << endl;
    return 0;
}
