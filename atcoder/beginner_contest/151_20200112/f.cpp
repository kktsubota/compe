#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

typedef long double ld;

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    ld radius;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    if (n == 2) {
        int dx = x[1] - x[0];
        int dy = y[1] - y[0];
        int dist = dx * dx + dy * dy;
        radius = sqrt((ld) dist) / 2.0;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // variable cx, cy
                    // ax * cx + ay * cy = a2 * 0.5
                    // bx * cx + by * cy = b2 * 0.5
                    int ax = (x[j] - x[i]);
                    int ay = (y[j] - y[i]);
                    int a2 = (x[j] * x[j] + y[j] * y[j] - x[i] * x[i] - y[i] * y[i]);
                    int bx = (x[k] - x[i]);
                    int by = (y[k] - y[i]);
                    int b2 =  (x[k] * x[k] + y[k] * y[k] - x[i] * x[i] - y[i] * y[i]);

                    // center
                    int div;
                    ld cx, cy;

                    // in the same line
                    if (ax * by - bx * ay == 0) {
                        cx = (ld) (max({x[i], x[j], x[k]}) + min({x[i], x[j], x[k]})) * 0.5;
                        cy = (ld) (max({y[i], y[j], y[k]}) + min({y[i], y[j], y[k]})) * 0.5;
                    } else {
                        div = ax * by - bx * ay;
                        cx = (ld) (a2 * by - b2 * ay) / (ld) div * 0.5;
                        cy = (ld) (b2 * ax - a2 * bx) / (ld) div * 0.5;
                    }
                    // distance from the center
                    vector<ld> distance;
                    for (int l = 0; l < n; l++) {
                        ld dx = (ld) x[l] - cx;
                        ld dy = (ld) y[l] - cy;
                        ld d = sqrt(dx * dx + dy * dy);
                        distance.push_back(d);
                    }
                    if (i == 0 && j == 1 && k == 2) {
                        radius = *max_element(distance.begin(), distance.end());
                    } else {
                        radius = min(radius, *max_element(distance.begin(), distance.end()));                        
                    }
                }
            }
        }
    }
    cout << setprecision(12) << radius << endl;
    return 0;
}
