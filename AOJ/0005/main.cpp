#include <iostream>
#include <complex>
#include <vector>
#include <unordered_map> 
#include <algorithm>

/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2014&lang=jp
 * test of c++
 */


class Field {
    public:
        std::vector<std::vector<int>> field;
        int height;
        int width;

        Field(std::vector<std::vector<int>>& input_vec) {
            height = input_vec.size();
            width = input_vec.at(0).size();
            field = input_vec;
        }

        void flip_bw() {
            for (int raw = 0; raw < height; raw++) {
                for (int col = 0; col < width; col++) {
                    field.at(raw).at(col) = -field.at(raw).at(col);
                }
            }
        }

        std::vector<std::vector<bool>> neighboring() {
            // adjacency for 1.
            std::vector<std::vector<bool>> adjacency;
            std::vector<std::vector<bool>> checked;
            adjacency = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
            for (int raw = 0; raw < height; raw++) {
                for (int col = 0; col < width; col++) {
                    if (field.at(raw).at(col) != 0) {
                        continue;
                    }
                    // to avoid loop
                    checked = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
                    isNeighboring(raw, col, adjacency, checked);
                }
            }
            return adjacency;
        }

        bool isNeighboring(int raw, int col, std::vector<std::vector<bool>>& adjacency, std::vector<std::vector<bool>>& checked) {
            // catch Out of Bounds here.
            if (raw < 0 || col < 0 || raw >= height || col >= width) {
                return false;
            }

            if (checked.at(raw).at(col)) {
                return adjacency.at(raw).at(col);
            }

            checked.at(raw).at(col) = true;
            if (field.at(raw).at(col) != 0) {
                adjacency.at(raw).at(col) = false;
                return false;
            }
            if (getField(raw, col-1) == 1 || getField(raw, col+1) == 1 || getField(raw-1, col) == 1 || getField(raw+1, col) == 1) {
                adjacency.at(raw).at(col) = true;
                return true;
            }

            if (isNeighboring(raw, col-1, adjacency, checked) || isNeighboring(raw, col+1, adjacency, checked)) {
                adjacency.at(raw).at(col) = true;
                return true;
            }
            if (isNeighboring(raw-1, col, adjacency, checked) || isNeighboring(raw+1, col, adjacency, checked)) {
                adjacency.at(raw).at(col) = true;
                return true;                
            }
            adjacency.at(raw).at(col) = false;
            return false;
        }

        int getField(int raw, int col) {
            if (raw < 0 || col < 0 || raw >= height || col >= width) {
                return -2;
            }
            return field.at(raw).at(col);
        }
};


template <typename T>
void printVector2d(std::vector<std::vector<T>>& matrix) {
    int h = matrix.size();
    int w = matrix.at(0).size();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cout << matrix.at(i).at(j);
        }
        std::cout << std::endl;
    }
}


template <typename T>
std::vector<std::vector<T>> read_input() {
    std::string input_str;

    std::getline(std::cin, input_str);
    std::istringstream iss(input_str);
    T width, height;
    iss >> width >> height;

    std::vector<std::vector<T>> input_vec(height, std::vector<int>(width, 0));

    for (size_t i = 0; i < height; i++) {
        std::getline(std::cin, input_str);
        for (size_t j = 0; j < width; j++) {
            if (input_str.at(j) == 'W') {
                input_vec.at(i).at(j) = 1;
            }
            else if (input_str.at(j) == 'B') {
                input_vec.at(i).at(j) = -1;
            }
        }
    }
    return input_vec;
}


int main(int argc, char const *argv[]) {
    while (true) {
        std::vector<std::vector<int>> input_vec = read_input<int>();
        if (input_vec.size() == 0) {
            break;
        }
        Field field = Field(input_vec);
        std::vector<std::vector<bool>> white_adjacency = field.neighboring();
        // std::cout << "white adjacency" << std::endl;
        // printVector2d<bool>(white_adjacency);

        field.flip_bw();
        std::vector<std::vector<bool>> black_adjacency = field.neighboring();
        // std::cout << "black adjacency" << std::endl;
        // printVector2d<bool>(black_adjacency);

        int white = 0;
        int black = 0;
        for (int raw = 0; raw < field.height; raw++) {
            for (int col = 0; col < field.width; col++) {
                if (white_adjacency.at(raw).at(col) && !black_adjacency.at(raw).at(col)) {
                    white++;
                }
                else if (!white_adjacency.at(raw).at(col) && black_adjacency.at(raw).at(col)) {
                    black++;
                }
            }
        }
        std::cout << black << " " << white << std::endl;
    }
    return 0;
}
