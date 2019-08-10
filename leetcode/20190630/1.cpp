class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int num = 1;
        while (candies != 0) {
            int index = (num - 1) % num_people;
            if (candies <= num) {
                num = candies;
            }
            ans[index] += num;
            candies -= num;
            num++;
        }
        return ans;
    }
};