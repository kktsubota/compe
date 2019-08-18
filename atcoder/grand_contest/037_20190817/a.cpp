#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    // string s(200000, 'a');
    int count = 0;
    int head_prev, tail_prev;
    for (int i = 1; i <= s.length(); i++) {
        if (i == 1) {
            count++;
            head_prev = 0;
            tail_prev = 1;
        } else {
            string s_prev = s.substr(head_prev, tail_prev - head_prev);
            if (s_prev == s.substr(tail_prev, i - tail_prev)) {
                continue;
            } else {
                count++;
                head_prev = tail_prev;
                tail_prev = i;
            }
        }
        // the rest is added to the final substr.
    }
    cout << count << endl;
    return 0;
}