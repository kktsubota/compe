#include <vector>
#include <iostream>


class Solution {
public:
    int maxScoreSightseeingPair(std::vector<int>& A) {
        int ans = 0;
        int limit;
        for (int diff = 1;; diff++) {
            limit = std::min((int) A.size(), 1000 * 2 - ans);
            if (diff >= limit) {
                break;
            }
            int value = 0;
            for (int i = 0; i < A.size() - diff; i++) {
                value = std::max(value, A[i] + A[i + diff]);
            }
            value = value - diff;
            ans = std::max(value, ans);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    // std::vector<int> a{8, 1, 5, 2, 6};
    std::vector<int> a{1, 2};

    Solution sol = Solution();
    int out = sol.maxScoreSightseeingPair(a);
    std::cout << out << std::endl;
    return 0;
}
