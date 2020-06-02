#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int a, b, c;
    cin >> a >> b >> c;
    if (b + c <= a) {
        c = 0;
    } else {
        c = c - (a - b);
    }
    cout << c << endl;
    return 0;
}
