#include <unordered_set>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <tuple>


int main(int argc, char const *argv[]) {
    int H, W;
    std::cin >> H >> W;
    std::vector<std::string> A(H);
    for (int i = 0; i < H; i++) {
        std::string A_row;
        std::cin >> A_row;
        A[i] = A_row;
    }

    std::queue<std::tuple<int, int, int>> black_mass;
    int count = 0;
    std::unordered_set<int> is_checked;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                std::tuple<int, int, int> tp = std::make_tuple(count, i, j);
                black_mass.push(tp);
            }
        }
    }
    while (!black_mass.empty()) {
        auto tp = black_mass.front();
        int& c = std::get<0>(tp);
        int& i = std::get<1>(tp);
        int& j = std::get<2>(tp);

        int pos = i * W + j;
        if (is_checked.find(pos) != is_checked.end()) {
            black_mass.pop();
            continue;
        } else {
            is_checked.insert(pos);
            count = c;

            if (i >= 1 && is_checked.find((i - 1) * W + j) == is_checked.end()) {
                black_mass.push(std::make_tuple(count + 1, i - 1, j));
            }
            if (j >= 1 && is_checked.find(i * W +  j - 1) == is_checked.end()) {
                black_mass.push(std::make_tuple(count + 1, i, j - 1));
            }
            if (i < H - 1 && is_checked.find((i + 1) * W + j) == is_checked.end()) {
                black_mass.push(std::make_tuple(count + 1, i + 1, j));
            }
            if (j < W - 1 && is_checked.find(i * W + j + 1) == is_checked.end()) {
                black_mass.push(std::make_tuple(count + 1, i, j + 1));
            }
            black_mass.pop();
        }
    }
    std::cout << count << std::endl;
    return 0;
}