#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> As(n);
    for (int i = 0; i < n; i++) {
        cin >> As[i];
    }
    // nlog(n)
    vector<int> values;
    make_heap(values.begin(), values.end());
    // vector<int> values;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            values.push_back(As[i]);
        } else {
            bool found = false;
            for (int j = 0; j < values.size(); j++) {
                if (values[values.size() - 1 - j] < As[i]) {
                    values[values.size() - 1 - j] = As[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                values.push_back(As[i]);
            }
            push_heap(values.begin(), values.end());
            sort_heap(values.begin(), values.end());
        }
    }
    // for (auto v: values) {
    //     cout << v << ",";
    // }
    // cout << endl;
    cout << values.size() << endl;
    return 0;
}
