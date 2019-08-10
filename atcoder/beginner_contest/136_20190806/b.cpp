#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= 1 && i <= 9) {
            count++;
        } else if (i >= 100 && i <= 999) {
            count++;
        } else if (i >= 10000 && i <= 99999) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
