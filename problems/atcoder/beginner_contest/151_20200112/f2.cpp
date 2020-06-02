#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> radius(1001);
    for (int i = 0; i <= 1000; i++) {
        vector<int> rad(1001);
        for (int j = 0; j <= 1000; j++) {
            // center is (i, j)
            vector<int> distance;
            for (int k = 0; k < n; k++) {
                int d = (x[k] - i) * (x[k] - i) + (y[k] - j) * (y[k] - j);
                distance.push_back(d);
            }
            rad[j] = *max_element(distance.begin(), distance.end());
        }
        radius[i] = *min_element(rad.begin(), rad.end());
    }
    double r = (double) *min_element(radius.begin(), radius.end());
    cout << setprecision(12) << sqrt(r) << endl;
    return 0;
}
