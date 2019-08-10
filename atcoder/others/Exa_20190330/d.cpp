// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <string>
// #include <numeric>
// #include <set>


// int main(int argc, char const *argv[])
// {
//     int N, X;
//     std::cin >> N >> X;
//     std::vector<int> Ss(N);
//     for(int i = 0; i < N; i++)
//     {
//         int s;
//         std::cin >> s;
//         Ss[i] = s;
//     }
//     // prepare dict
//     std::unordered_map<char, std::vector<int>> index_dict;
//     for (int i = 0; i < N; i++) {
//         index_dict[s.c_str()[i]].push_back(i);
//     }
//     // simulate
//     std::vector<int> golem(N, 1);
//     for (int i = 0; i < Q; i++) {
//         char t, d;
//         t = ts[i];
//         d = ds[i];

//         int offset;
//         if (d == 'L') {
//             offset = -1;
//         } else {
//             offset = 1;
//         }

//         for (auto idx: index_dict[t]) {
//             int idx_target = idx + offset;
//             if (idx_target >= 0 && idx_target < N) {
//                 golem[idx_target] += golem[idx];
//             }
//             golem[idx] = 0;
//         }
//         // disp golem
//         // for (auto elem: golem) {
//         //     std::cout << elem << " ";
//         // }
//         // std::cout << std::endl;
//     }
//     int sum = std::accumulate(golem.begin(), golem.end(), 0);
//     std::cout << sum << std::endl;

//     return 0;
// }
