class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> ans_set;
        int n = tiles.length();
        for (int bit = 0; bit < (1<<n); ++bit) {
            if (bit == 0) {
                // remove empty word
                continue;
            }
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                if (bit & (1<<i)) {
                    v.push_back(i);
                }
            }
            do {
                string s;
                for (auto index: v) {
                    s += tiles[index];
                }
                ans_set.insert(s);
            } while (std::next_permutation(v.begin(), v.end()));            
        }
        return (int) ans_set.size();
    }
};