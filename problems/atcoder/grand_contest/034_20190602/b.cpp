#include <iostream>
#include <string>


using namespace std;


int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int cnt = 0;
    int prev_cnt = 0;
    while (true) {
        int i = 0;
        while (i < (int) s.length() - 2) {
            if (s[i] == 'A' && s[i+1] == 'B' && s[i+2]) {
                s[i] = 'B';
                s[i+1] = 'C';
                s[i+2] = 'A';
                i += 2;
                cnt += 1;
            } else {
                i += 1;
            }
        }
        if (prev_cnt == cnt) {
            break;
        } else {
            prev_cnt = cnt;;
        }
    }
    cout << cnt << endl;
    return 0;
}
