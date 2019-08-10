#include <iostream>
#include <vector>
#include <numeric>


// priority_queue<int, vector<int>, greater<int>> pq;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        std::vector<size_t> indices(A.size());

        // faster by using binary tree N logN
        // our algorithm is N^2
        for (int i = 0; i < K; i++) {
            std::vector<int>::iterator iter = std::min_element(A.begin(), A.end());
            int index = std::distance(A.begin(), iter);
            A[index] = -A[index];
        }
        int ans = std::accumulate(A.begin(), A.end(), 0);
        return ans;
    }
};