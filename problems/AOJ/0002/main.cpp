#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>

/*
 *  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0584
 * test of c++
 */

class Node {
    private:
        int value;
    public:
        void setValue(int v) {
            value = v;
        }

        int getValue() {
            return value;
        }
};

class Tree {
    private:
        Node root;
        Node left;
        Node right;

    public:
        Tree() {
            // root < left < right
            int inf = 1000010001;
            root.setValue(inf);
            left.setValue(inf);
            right.setValue(inf);
        }

        void push(int value) {
            if (value < root.getValue()) {
                right.setValue(left.getValue());
                left.setValue(root.getValue());
                root.setValue(value);
            } 
            else if (value < left.getValue()) {
                right.setValue(left.getValue());
                left.setValue(value);
            }
            else if (value < right.getValue()) {
                right.setValue(value);
            } 
            // larget than any other data
            else {}
        }

        int get() {
            return right.getValue();
        }

        std::ostream& print(std::ostream& os) {
           return os << root.getValue() << "-" << left.getValue() << "-" << right.getValue() << std::endl;
        }
};


std::ostream& operator<< (std::ostream& os, Tree& obj){
    return obj.print(os);
}


int main(int argc, char const *argv[]) {
    std::string input_str;
    std::vector<std::string> input_vec;

    std::getline(std::cin, input_str);
    std::istringstream iss(input_str);
    int arr_size;
    iss >> arr_size;

    for (int i = 0; i < arr_size; i++) {
        std::getline(std::cin, input_str);
        input_vec.push_back(input_str);
    }

    Tree ans;
    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < arr_size; j++) {
            if (i == j) {
                continue;
            }
            std::string num_str = input_vec.at(i) + input_vec.at(j);

            // std::stringstream ss(num_str);
            // int num;
            // ss >> num;
            int num = std::stoi(num_str);
            ans.push(num);
        }
    }
    std::cout << ans.get() << std::endl;

    return 0;
}
