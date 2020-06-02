#include <iostream>
#include <complex>
#include <vector>
#include <unordered_map> 
#include <algorithm>
#include <tuple>

/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1277
 * test of c++
 * WRONG ANSWER
 */

// set problem as reccurence formula

std::tuple<int, int, std::vector<int>, std::vector<int>> read_input() {
    std::string input_str;

    std::getline(std::cin, input_str);
    std::istringstream iss(input_str);
    int size, trials, num_L, num_B;
    iss >> size >> trials >> num_L >> num_B;

    std::vector<int> points_L;
    std::vector<int> points_B;

    for (size_t i = 0; i < num_L; i++) {
        std::getline(std::cin, input_str);
        points_L.push_back(std::stoi(input_str));
    }
    for (size_t i = 0; i < num_B; i++) {
        std::getline(std::cin, input_str);
        points_B.push_back(std::stoi(input_str));
    }
    std::tuple<int, int, std::vector<int>, std::vector<int>> inputs = std::make_tuple(size, trials, points_L, points_B);
    return inputs;
}

template <typename T>
void printVector1d(std::vector<T> vec) {
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    while (true) {
        std::tuple<int, int, std::vector<int>, std::vector<int>> inputs = read_input();
        int size = std::get<0>(inputs);
        int trials = std::get<1>(inputs);
        std::vector<int> points_L = std::get<2>(inputs);
        std::vector<int> points_B = std::get<3>(inputs);

        if (size == 0 && trials == 0) {
            break;
        }
        // 0 - size: normal points
        // size + 1 - 2 * size: sleep points
        std::vector<long double> state(size*2+1, 0);
        state.at(0) = 1.0;

        for (int t = 0; t < trials; t++) {
            std::vector<long double> state_moved(size*2+1, 0);

            // transition
            for (int src = 0; src < size; src++) {
                // get the probability
                long double prob = state.at(src);
                // propagate
                for (int k = 1; k <= 6; k++) {
                    int target = src + k;
                    // over
                    if (src + k > size) {
                        target = size - target % size;
                    }
                    state_moved.at(target) += prob / 6;
                }
            }
            // when src == size, not move.
            state_moved.at(size) += state.at(size);
            // rest, copy them.
            for (int src = size + 1; src < size * 2 + 1; src++) {
                state_moved.at(src) = state.at(src);
            }

            // TODO: copy
            state = state_moved;

            // effect of each point
            // go back to the front
            for (int point_b: points_B) {
                state.at(0) += state.at(point_b);
                state.at(point_b) = 0;
            }
            // 1 <= point_l <= size - 1
            for (int point_l: points_L) {
                std::swap(state.at(size + point_l), state.at(point_l));
            }
        }
        std::cout << state.at(size) << std::endl;
    }
    return 0;
}
