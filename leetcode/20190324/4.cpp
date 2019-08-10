#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <bitset>

class Solution {
public:
    bool queryString(std::string S, int N) {
        bool ans = false;
        int length = (int) S.length();
        std::set<int> values{};
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j <= length; j++) {
                std::string subs = S.substr(i, j - i);
                // std::cout << subs << " (" << i << "," << j << ")" << std::endl;
                // int v = binary_to_dec(subs);
                int v;
                try {
                    v = (int) binary.to_ulong();
                } catch (...) {
                    return false;
                }
                values.insert(v);
            }
        }
        if (N > values.size()) {
            return false;
        }

        for (int k = N; k > 0; k--) {
            if (values.count(k) == 0) {
                return false;
            }
        }
        return true;
    }

    int binary_to_dec(std::string s) {
        std::bitset<8> binary(s);
        int v = (int) binary.to_ulong();
        return v;
    }
    
    std::string dec_to_binary(int n) {
        std::bitset<8> binary(n);
        // std::stringstream ss;
        // ss << binary;
        // ss.str();
        return binary.to_string();
    }
};

int main(int argc, char const *argv[])
{
    std::string S = "0110";
    int N = 3;

    Solution sol = Solution();
    // std::string out = sol.dec_to_binary(N);
    // std::cout << out << std::endl;
    // std::cout << sol.binary_to_dec(out) << std::endl;
    bool out = sol.queryString(S, N);
    std::cout << out << std::endl;
    return 0;
}
