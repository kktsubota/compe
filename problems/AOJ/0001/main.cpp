#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>

/*
 *  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_2_B#
 * test of c++
 */

int main(int argc, char const *argv[]) {
    std::string input_str;
    std::vector<int> input_vec;

    // for (int i = 0; !std::cin.eof(); i++) {
    //     int ret;
    //     std::cin >> input_str;
    //     std::istringstream iss(input_str);
    //     iss >> ret;
    //     input_vec.push_back(ret);
    // }

    std::getline(std::cin, input_str);
    std::istringstream iss(input_str);
    while (!iss.eof()) {
        int ret;
        iss >> ret;    
        input_vec.push_back(ret);
    }
    assert(input_vec.size() == 3);
    if(input_vec.at(0) < input_vec.at(1) && input_vec.at(1) < input_vec.at(2)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
