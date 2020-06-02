#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> As(N);
    vector<int> Bs(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        As[i] = a;
        Bs[i] = b;
    }
    // sort(As.begin(), As.end());
    // sort(Bs.begin(), Bs.end());
    return 0;
}
