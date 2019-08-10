#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
typedef long long unsigned int ll;

#include <algorithm>


class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        std::vector<int> values = {a, b, c};
        std::sort(values.begin(), values.end());
        int diff_1 = values[1] - values[0];
        int diff_2 = values[2] - values[1];
        int ans_min = 0;
        if (diff_1 == 2 || diff_2 == 2) {
            ans_min += 1;
        } else {
            if (diff_1 != 1) {
                ans_min += 1;
            }
            if (diff_2 != 1) {
                ans_min += 1;
            }            
        }
        int ans_max = (diff_1 - 1) + (diff_2 - 1);
        std::vector<int> ans = {ans_min, ans_max};
        return ans;
    }
};

// [[2,1,3,2,1,1,3],[1,2,3,1,3,1,3],[1,2,1,3,2,3,3],[2,1,3,3,2,3,3],[2,3,3,3,3,1,3]]