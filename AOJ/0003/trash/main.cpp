#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <array>
/* https://en.wikipedia.org/wiki/Closest_pair_of_points_problem
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0585
 * test of c++
 */


template <typename T>
class NpArray {
    private:        
        std::vector<T> arr;
        int size_x;
        int size_y;
    public:
        NpArray(int x, int y) {
            size_x = x;
            size_y = y;
            arr.resize(x*y);
            for (int i = 0; i < size_x*size_y; i++) {
                arr[i] = 0;
            }
        }

        NpArray operator+(NpArray &arr2) {
            NpArray<T> arr_ret = NpArray(size_x, size_y);
            for (int i = 0; i < size_x; i++) {
                for (int j = 0; j < size_y; j++) {
                    arr_ret[i, j] = this[i, j] + arr2[i, j];
                }
            }
            return arr_ret;
        }

        NpArray operator-(NpArray &arr2) {
            NpArray<T> arr_ret = NpArray(size_x, size_y);
            for (int i = 0; i < size_x; i++) {
                for (int j = 0; j < size_y; j++) {
                    arr_ret[i, j] = this[i, j] - arr2[i, j];
                }
            }
            return arr_ret;
        }

        NpArray operator*(NpArray &arr2) {
            NpArray<T> arr_ret = NpArray(size_x, size_y);
            for (int i = 0; i < size_x; i++) {
                for (int j = 0; j < size_y; j++) {
                    arr_ret[{i, j}] = this[{i, j}] * arr2[{i, j}];
                }
            }
            return arr_ret;
        }

        NpArray sum(int axis = -1) {
            if (axis == 0) {
                NpArray<T> arr_ret = NpArray(size_y, 1);
                for (int i = 0; i < size_x; i++) {
                    for (int j = 0; j < size_y; j++) {
                        arr_ret.setValue(i, 0, arr_ret[i, 0] + arr[i*size_y+j]);
                    }
                }
                return arr_ret;            
            }
            else if (axis = 1) {
                NpArray<T> arr_ret = NpArray(size_x, 1);
                for (int i = 0; i < size_x; i++) {
                    for (int j = 0; j < size_y; j++) {
                        arr_ret.setValue(j, 0, arr_ret[j, 0] + arr[i*size_y+j]);
                    }
                }
                return arr_ret;
            }
            else {
                NpArray<T> arr_ret = NpArray(1, 1);
                for (int i = 0; i < size_x*size_y; i++) {
                    arr_ret.setValue(0, 0, arr_ret[0, 0] + arr[i]);
                }
                return arr_ret;                
            }
        }

        T operator[](int* idx) {
            int i = idx[0];
            int j = idx[1];
            return arr[i][j];
        }
        
        void setValue(int i, int j, T value) {
            arr[i*size_y+j] = value;
        }

        int* shape() {
            return {size_x, size_y};
        }

        std::ostream& print(std::ostream& os) {
            os << "[";
            for (int i = 0; i < size_x; i++) {
                os << "[";
                for (int j = 0; j < size_y; j++) {
                    os << arr[i*size_y+j] << ", ";
                }
                os << "]" << std::endl;
            }
            os << "]";
            return os;
        }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, NpArray<T>& obj){
    return obj.print(os);
}


NpArray<double> read_input() {
    std::string input_str;

    std::getline(std::cin, input_str);
    int arr_size = std::stoi(input_str);
    NpArray<double> input_vec(arr_size, 2);

    for (int i = 0; i < arr_size; i++) {
        std::getline(std::cin, input_str);
        std::istringstream iss(input_str);
        int value;
        iss >> value;
        input_vec.setValue(i, 0, value);
        iss >> value;
        input_vec.setValue(i, 1, value);
    }
    return input_vec;
}

int main(int argc, char const *argv[]) {
    NpArray<double> input_vec = read_input();
    std::cout << input_vec << std::endl;

    NpArray<double> vec(input_vec.shape[0], input_vec.shape[1]);
    NpArray<double> add = input_vec + vec;
    std::cout << add << std::endl;
    NpArray<double> diff = input_vec - vec;
    std::cout << diff << std::endl;
    NpArray<double> ret = input_vec * vec;
    std::cout << ret  << std::endl;
    NpArray<double> sum = ret.sum(1);
    std::cout << sum << std::endl;
    // int num = std::stoi(num_str);
    // ans.push(num);
    // std::cout << ans.get() << std::endl;

    return 0;
}
