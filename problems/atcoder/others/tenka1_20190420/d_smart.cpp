#include <vector>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <string>

#define MOD 998244353


int pow(const int base, const int n) {
    if (n == 0) {
        return 1;
    } else {
        return base * pow(base, n - 1) % MOD;    
    }
}

std::string hash_value(int a, int b) {
    return std::to_string(a) + " " + std::to_string(b);
}


std::string hash_value(int a, int b, int c) {
    return std::to_string(a) + " " + std::to_string(b) + " " + std::to_string(c);
}

// R >= S/2, N
int larger_than_T(int T, int k, std::vector<int>& As, std::unordered_map<std::string, int>& cache) {
    // equal to or larger than T in As[:k]
    if (k == 0) {
        if (T <= 0) {
            return 1;
        } else {
            return 0;
        }
    }
    const std::string tp = hash_value(T, k);
    if (cache.find(tp) == cache.end()) {
        // assign As[k-1] to G or B 
        const int value_1 = 2 * larger_than_T(T, k - 1, As, cache) % MOD;
        const int value_2 = larger_than_T(T - As[k-1], k - 1, As, cache) % MOD;
        cache[tp] = (value_1 + value_2) % MOD;
    }
    // std::cout << "T: " << T << "k: " << k << "v: " << cache[tp] << std::endl;
    return cache[tp]; 
}

// R = G = S/2, N
int equal_to_Ts(const int T1, const int T2, const int k, std::vector<int>& As, std::unordered_map<std::string, int>& cache) {
    // R and G are equal to T1 and T2 respectively in As[:k].
    if (T1 < 0 || T2 < 0) {
        return 0;
    }
    if (k == 0) {
        if (T1 == 0 && T2 == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    const std::string tp = hash_value(T1, T2, k);
    if (cache.find(tp) == cache.end()) {
        const int value_1 = equal_to_Ts(T1, T2, k - 1, As, cache) % MOD;
        const int value_2 = equal_to_Ts(T1 - As[k-1], T2, k - 1, As, cache) % MOD;
        const int value_3 = equal_to_Ts(T1, T2 - As[k-1], k - 1, As, cache) % MOD;

        cache[tp] = (value_1 + value_2 + value_3) % MOD;
    }
    return cache[tp];
}

int main(int argc, char const *argv[])
{
    int N;
    std::vector<int> As(N);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> As[i];
    }
    int S = 0;
    for (int i = 0; i < N; i++) {
        S += As[i];
    }
    const int base = pow(3, N);
    // std::cout << base << std::endl;

    const int T = S % 2 == 0 ? S / 2 : S / 2 + 1;
    // std::vector<std::vector<int>> cache_1(T + 1, std::vector<int>(N + 1, -1));
    std::unordered_map<std::string, int> cache_1;
    const int value_1 = larger_than_T(T, N, As, cache_1);
    // std::cout << value_1 << std::endl;

    int value_2 = 0;
    if (S % 2 == 0) {
        // std::vector<std::vector<std::vector<int>>> cache_2(S/2 + 1, std::vector<std::vector<int>>(S/2 + 1, std::vector<int>(N + 1, -1)));
        std::unordered_map<std::string, int> cache_2;
        value_2 = equal_to_Ts(S / 2, S / 2, N, As, cache_2);
    }
    // std::cout << value_2 << std::endl;

    // print(base, single, double)
    int ans = (base - value_1 * 3 + value_2 * 3) % MOD;
    while (ans < 0) {
        ans += MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}