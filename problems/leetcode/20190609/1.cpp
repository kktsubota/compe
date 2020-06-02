#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words = split(text, " ");
        vector<string> ans;
        for (int i = 0; i < words.size() - 2; i++) {
            if (words[i].compare(first) == 0 && words[i + 1].compare(second) == 0) {
                ans.push_back(words[i + 2]);
            }
        }
        return ans;
    }
    
    vector<string> split(const string text, const string delim) {
        vector<string> vec;
        int head = 0;
        int tail = head;
        while (tail < text.length()) {
            if (text.substr(tail, delim.length()).compare(delim) == 0) {
                vec.push_back(text.substr(head, tail - head));
                head = tail + delim.length();
                tail = head;
            } else {
                tail++;
            }
        }
        vec.push_back(text.substr(head, tail));
        return vec;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> out = sol.split("hogehoge", "h");
    for (auto o: out) {
        cout << o << "/";
    }
    cout << endl;
    return 0;
}
