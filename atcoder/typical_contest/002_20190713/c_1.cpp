#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<long long int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    map<pair<int, int>, long long int> costs;
    for (int offset = 0; offset <= n; offset++) {
        for (int head = 0; head <= n - offset; head++) {
            int tail = head + offset;
            pair<int, int> index = make_pair(head, tail);
            long long int w_sum = accumulate(weight.begin() + head, weight.begin() + tail, 0);
            if (offset == 1) {
                costs[index] = 0LL;
            } else if (offset == 2) {
                costs[index] = w_sum;
            } else {
                long long int cost = __LONG_LONG_MAX__;
                for (int k = 1; head + k < tail; k++) {
                    auto index_1 = make_pair(head, head + k);
                    auto index_2 = make_pair(head + k, tail);
                    cost = min(costs[index_1] + costs[index_2] + w_sum, cost);
                }
                costs[index] = cost;
            }
            // cout << index.first << ", " << index.second << ": " << costs[index] << endl;
        }
    }
    cout << costs[make_pair(0, n)] << endl;    
    return 0;
}
