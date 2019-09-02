#include <vector>
#include <iostream>
#include <utility>
// #include <algorithm>
// #include <numeric>
// #include <map>
#include <set>
#include <deque>
// #include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<deque<pair<int, int>>> vs_table(n);
    for (int i = 0; i < n; i++) {
        deque<pair<int, int>> vs_row(n - 1);
        for (int j = 0; j < n - 1; j++) {
            int r;
            cin >> r;
            vs_row[j] = make_pair(i, r - 1);
        }
        vs_table[i] = vs_row;
    }
    set<pair<int, int>> schedule;
    set<pair<int, int>> schedule_check;
    for (int i = 0; i < n; i++) {
        pair<int, int>& vs = vs_table[i].front();
        vs_table[i].pop_front();
        schedule_check.insert(vs);
    }

    int ans = 0;
    while (!schedule_check.empty()) {
        // cout << "schedule";
        // for (auto vs: schedule) {
        //     cout << "(" << vs.first << ", " << vs.second << ")";
        // }
        // cout << endl;
        for (auto vs: schedule_check) {
            schedule.insert(vs);
        }

        set<pair<int, int>> schedule_rm;
        for (pair<int, int> vs: schedule_check) {
            pair<int, int> vs_inv = make_pair(vs.second, vs.first);
            if (schedule.find(vs_inv) != schedule.end()) {
                schedule_rm.insert(vs);
                schedule_rm.insert(vs_inv);
            }
        }
        schedule_check.clear();
        // cout << "schedule_rm";
        // for (auto vs: schedule_rm) {
        //     cout << "(" << vs.first << ", " << vs.second << ")";
        // }
        // cout << endl;
        if (schedule_rm.empty()) {
            ans = -1;
            break;
        }
        ans++;
        // erase and prepare for the next step
        for (pair<int, int> vs: schedule_rm) {
            schedule.erase(vs);
            if (!vs_table[vs.first].empty()) {
                pair<int, int>& vs_next = vs_table[vs.first].front();
                vs_table[vs.first].pop_front();
                schedule_check.insert(vs_next);
            }
        }
   }
    cout << ans << endl;   
    return 0;
}
