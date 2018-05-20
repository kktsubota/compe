#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <sstream>

/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1367
 * test of c++
 */


template <typename T>
std::vector<T> read_input(int &arr_size) {
    std::string input_str;

    std::getline(std::cin, input_str);
    std::istringstream iss(input_str);
    int size, request_size;
    iss >> size >> request_size;
    arr_size = size;

    // this is for myself
    std::vector<T> input_vec(request_size);

    for (int i = 0; i < request_size; i++) {
        std::getline(std::cin, input_str);
        input_vec.at(i) = std::stoi(input_str);
    }
    return input_vec;
}


int main(int argc, char const *argv[]) {
    int arr_size;
    std::vector<int> requests = read_input<int>(arr_size);
    std::vector<int> arr(arr_size);
    std::vector<bool> moved(arr_size, false);
    for (int i = 0; i < arr_size; i++) {
        arr.at(i) = i + 1;
    }

    // moved objects
    std::list<int> header;
    for (auto iter = requests.rbegin(); iter != requests.rend(); ++iter) {
        int value = *iter;
        // std::cout << "requested value: " << value << std::endl;
        if (!moved.at(value - 1)) {
            moved.at(value - 1) = true;
            header.push_back(value);
        }
    }

    // not moved objects
    std::list<int> footer;
    for (int i = 0; i < arr_size; i++) {
        if (!moved.at(i)) {
            // std::cout << "not moved value: " << arr.at(i) << std::endl;
            footer.push_back(arr.at(i));
        }
    }
    header.insert(header.end(), footer.begin(), footer.end());
    for (auto value: header) {
        std::cout << value << std::endl;
    }
    return 0;
}
