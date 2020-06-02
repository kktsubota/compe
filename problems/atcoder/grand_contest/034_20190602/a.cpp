#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool has_two_rocks(string S, int A, int C) {
    for (int i = A; i <= C - 1; i++) {
        if (S[i] == '#' && S[i+1] == '#') {
            return true;
        }
    }
    return false;
}

bool has_three_spaces(string S, int A, int C) {
    for (int i = A; i <= C; i++) {
        if (i >= S.length() - 1 || i == 0) {
            continue;
        }
        if (S[i-1] == '.' && S[i] == '.' && S[i+1] == '.') {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D;
    A -= 1;
    B -= 1;
    C -= 1;
    D -= 1;
    cin >> S;
    if (C < D) {
        if (has_two_rocks(S, A, C) || has_two_rocks(S, B, D)) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    } else {
        // A jumps over B
        if (!has_two_rocks(S, B, D) && has_three_spaces(S, B, D) && !has_two_rocks(S, A, C)) {
            cout << "Yes" << endl;
        }  else {
            cout << "No" << endl;
        }
    }
    return 0;
}
