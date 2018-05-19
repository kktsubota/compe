#include <iostream>
#include <complex>
#include <vector>
#include <unordered_map> 
#include <algorithm>

/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2331&lang=jp
 * test of c++
 */


template <typename T>
std::vector<std::vector<T>> read_input() {
    std::string input_str;

    std::getline(std::cin, input_str);
    int arr_size = std::stoi(input_str);
    std::vector<std::vector<T>> input_vec(arr_size, std::vector<int>(2, 0));

    for (size_t i = 0; i < arr_size; i++) {
        std::getline(std::cin, input_str);
        std::istringstream iss(input_str);
        T begin, end;
        iss >> begin >> end;

        // this is for myself
        begin -= 1;
        end -= 1;
        input_vec.at(i).at(0) = begin;
        input_vec.at(i).at(1) = end;
    }
    return input_vec;
}


int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> input_vec = read_input<int>();
    // search(input_vec, 0, input_vec.size(), &ans);

    // counts[j] people can endure j+1 people.
    std::vector<int> counts(input_vec.size(), 0);
    for (int i = 0; i < input_vec.size(); i++) {
        std::vector<int> person = input_vec.at(i);
        for (int j = person.at(0); j <= person.at(1) && j <= counts.size(); j++) {
            counts.at(j-1) += 1;
        }
    }
    // for (int i = 0; i < counts.size(); i++) {
    //     std::cout << counts.at(i);
    // }
    // std::cout << std::endl;

    int ans = 0;
    for (int i = 0; i < counts.size(); i++) {
        if (counts.at(i) > i) {
            ans = i + 1;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
