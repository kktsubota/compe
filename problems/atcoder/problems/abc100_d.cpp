#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    
    set<ll> ans;
    for (int sign_x = 0; sign_x <= 1; sign_x++) {
        for (int sign_y = 0; sign_y <= 1; sign_y++) {
            for (int sign_z = 0; sign_z <= 1; sign_z++) {
                vector<ll> sum_list(n, 0LL);
                for (int i = 0; i < n; i++) {
                    if (sign_x == 0) {
                        sum_list[i] += x[i];
                    } else {
                        sum_list[i] -= x[i];
                    }
                    if (sign_y == 0) {
                        sum_list[i] += y[i];
                    } else {
                        sum_list[i] -= y[i];
                    }
                    if (sign_z == 0) {
                        sum_list[i] += z[i];
                    } else {
                        sum_list[i] -= z[i];
                    }
                }
                sort(sum_list.begin(), sum_list.end());
                ll s = 0LL;
                for (int i = 1; i <= m; i++) {
                    s += sum_list[n - i];
                }
                ans.insert(s);
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;

    return 0;
}

