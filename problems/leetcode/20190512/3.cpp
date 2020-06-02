#include <unordered_map>
#include <pair>
#include <utility>
#include <algorithm>

// 問題文の読み間違え
// Kこに分割かと思ったら、最長Kだった

namespace std {
    template <>
    class hash<std::pair<int, int>> {
    public:
        size_t operator()(const std::pair<int, int>& x) const{
            return hash<int>()(x.first) ^ hash<int>()(x.second);
        }
    };
}

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        unordered_map<pair<int, int>, int> cache;
        return maxSumPart(A, A.size(), K, cache);
    }
    
    int maxSumPart(vector<int>& A, int n, int k, unordered_map<pair<int, int>, int>& cache) {
        auto p = make_pair(n, k);
        if (n <= 0) {
            return 0;
        }
        if (k == 1) {
            return *max_element(A.begin(), A.begin() + n) * n;
        }
        if (n < k) {
            return 0;
        }
        if (cache.find(p) == cache.end()) {
            int max_score = 0;
            for (int j = 1; j <= n - k; j++) {
                int score = maxSumPart(A, n - j, k - 1, cache) + *max_element(A.begin() + n - j, A.begin() + n) * j;
                max_score = std::max(max_score, score);
            }
            cache[p] = max_score;
        }
        return cache[p];
    }
};