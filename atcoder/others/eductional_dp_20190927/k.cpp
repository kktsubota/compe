#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[]) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<bool> win(K + 1);
    for (int i = 0; i <= K; i++) {
        if (*min_element(A.begin(), A.end()) > i) {
            win[i] = false;
        } else {
            bool win_flag = false;
            for (int a: A) {
                if (i < a) {
                    continue;
                } else {
                    if (!win[i - a]) {
                        win_flag = true;
                        break;
                    }
                }
            }
            win[i] = win_flag;
        }
    }
    if (win[K]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}
