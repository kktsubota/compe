#include <vector>
#include <iostream>

#define MOD 998244353


int pow(const int base, const int n) {
    if (n == 0) {
        return 1;
    } else {
        return base * pow(base, n - 1) % MOD;    
    }
}

// R >= S/2, N
int larger_than_T(int T, int k, std::vector<int>& As, std::vector<std::vector<int>>& cache) {
    // equal to or larger than T in As[:k]
    if (k == 0) {
        if (T <= 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (T < 0) {
        return pow(3, k) % MOD;
    }
    if (cache[T][k] == -1) {
        // assign As[k-1] to G or B 
        const int value_1 = 2 * larger_than_T(T, k - 1, As, cache) % MOD;
        const int value_2 = larger_than_T(T - As[k-1], k - 1, As, cache) % MOD;
        cache[T][k] = (value_1 + value_2) % MOD;
    }
    std::cout << "T: " << T << "k: " << k << "v: " << cache[T][k] << std::endl;
    return cache[T][k]; 
}

// R = G = S/2, N
int equal_to_Ts(const int T1, const int T2, const int k, std::vector<int>& As, std::vector<std::vector<std::vector<int>>>& cache) {
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
    if (cache[T1][T2][k] == -1) {
        const int value_1 = equal_to_Ts(T1, T2, k - 1, As, cache) % MOD;
        const int value_2 = equal_to_Ts(T1 - As[k-1], T2, k - 1, As, cache) % MOD;
        const int value_3 = equal_to_Ts(T1, T2 - As[k-1], k - 1, As, cache) % MOD;

        cache[T1][T2][k] = (value_1 + value_2 + value_3) % MOD;
    }
    return cache[T1][T2][k];
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
    std::cout << base << std::endl;

    const int T = S % 2 == 0 ? S / 2 : S / 2 + 1;
    std::vector<std::vector<int>> cache_1(T + 1, std::vector<int>(N + 1, -1));
    const int value_1 = larger_than_T(T, N, As, cache_1);
    std::cout << value_1 << std::endl;

    int value_2 = 0;
    if (S % 2 == 0) {
        std::vector<std::vector<std::vector<int>>> cache_2(S/2 + 1, std::vector<std::vector<int>>(S/2 + 1, std::vector<int>(N + 1, -1)));
        value_2 = equal_to_Ts(S / 2, S / 2, N, As, cache_2);
    }
    std::cout << value_2 << std::endl;

    // print(base, single, double)
    const int ans = (base - value_1 * 3 + value_2 * 3) % MOD;
    std::cout << ans << std::endl;
    return 0;
}