#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    int MOD = 1000000007;
    int N, K;
    cin >> N >> K;
    unordered_map<int, vector<long long int>> comb;
    comb[0].push_back(1LL);
    comb[1].push_back(1LL);
    comb[1].push_back(1LL);
    for (int i = 2; i <= max(N - K + 1, K - 1); i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                comb[i].push_back(1LL);
            } else {
                long long int value = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
                comb[i].push_back(value);
            }
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     auto vec = comb[i];
    //     for (auto v: vec) {
    //         cout << v << ", ";
    //     }
    //     cout << endl;
    // }

    long long int ans;
    for (int l = 1; l <= K; l++) {
        if (l > N - K + 1) {
            ans = 0;
        } else {
            // N-K+1_C_l * (K + l - 1)_C_K
            ans = comb[N - K + 1][l] * comb[K - 1][l - 1] % MOD;
        }
        cout << ans << endl;

    }
    return 0;
}
