#include <iostream>
#include <complex>
#include <vector>
#include <unordered_map> 
#include <algorithm>


/* https://en.wikipedia.org/wiki/Closest_pair_of_points_problem
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0585
 * test of c++
 */

template <typename T>
class Region {
    private:
        std::vector<std::complex<T>> points;
        T d_min;
    
    public:
        T getDist() {
            return d_min;
        }
        
        void setDist(T dist) {
            this->d_min = dist;
        }

        std::vector<std::complex<T>> getPoint() {
            return points;
        }

        void setPoint(std::vector<std::complex<T>> points) {
            this->points = points;
        }

        Region operator+(Region<T> &region_r) {
            std::vector<std::complex<T>> points_r = region_r.getPoint();
            T dist_r = region_r.getDist();

            T d_min_lr =  std::min(d_min, dist_r);
            
            T d_inter = __INT_MAX__;

            // this is to avoid zero division.
            if (d_min_lr != 0) {
                T left_boundary = -__INT_MAX__;
                for (auto point_l: this->points) {
                    left_boundary = std::max(left_boundary, point_l.real());
                }

                // divide right points to blocks following the wiki.
                // key works as a hash.
                std::unordered_map<int, std::vector<std::complex<int>>> blocks;
                for (auto point_r: points_r) {
                    if ((point_r.real() - left_boundary) > d_min_lr) {
                        continue;
                    }
                    int key = point_r.imag() / d_min_lr;
                    blocks[key].push_back(point_r);
                }

                // main loop
                for (auto point_l: this->points) {
                    int key = point_l.imag() / d_min_lr;

                    // up and down of right blocks
                    for (int i = key - 1; i < key + 2; i++) {
                        std::vector<std::complex<int>> points_r_blk = blocks[i];
                        for (auto point_r: points_r_blk) {
                            d_inter = std::min(d_inter, std::norm(point_l - point_r));
                        }
                    }
                }
            }

            // operator+ destructs myself
            this->d_min = std::min(d_min_lr, d_inter);
            this->points.insert(this->points.end(), points_r.begin(), points_r.end());

            return *this;
        }
};


template <typename T>
std::vector<std::complex<T>> read_input() {
    std::string input_str;

    std::getline(std::cin, input_str);
    int arr_size = std::stoi(input_str);
    std::vector<std::complex<T>> input_vec(arr_size);

    for (size_t i = 0; i < arr_size; i++) {
        std::getline(std::cin, input_str);
        std::istringstream iss(input_str);
        int real, imag;
        iss >> real >> imag;
        std::complex<T> point(real, imag);
        input_vec.at(i) = point;
    }
    return input_vec;
}


std::vector<Region<int>> sort_and_divide(std::vector<std::complex<int>> points) {
    std::vector<Region<int>> regions(points.size());

    // sort by real value
    std::sort(points.begin(), points.end(), [](std::complex<int>& p1, std::complex<int>& p2) {return p1.real() < p2.real();});

    // divide
    for (size_t i = 0; i < points.size(); i++) {
        std::vector<std::complex<int>> point({points.at(i)});
        regions.at(i).setPoint(point);
        regions.at(i).setDist(__INT_MAX__);
    }
    return regions;
}


int find_smart(std::vector<std::complex<int>> points) {
    std::vector<Region<int>> regions = sort_and_divide(points);

    while (regions.size() != 1) {
        std::vector<Region<int>> regions_merged;
        for (size_t i = 0; i < regions.size(); i++) {
            if (i % 2 == 1) {
                Region<int> region = regions.at(i-1) + regions.at(i);
                regions_merged.push_back(region);
            }
        }
        if (regions.size() % 2 == 1) {
            regions_merged.push_back(regions.at(regions.size()-1));
        }

        regions = regions_merged;
    }
    return regions.at(0).getDist();
}


int find_naive(std::vector<std::complex<int>> points) {
    int ans = __INT_MAX__;
    size_t arr_size = points.size();
    for (size_t i = 0; i < arr_size; i++) {
        for (size_t j = i + 1; j < arr_size; j++) {
            int dist2 = std::norm(points.at(j) - points.at(i));
            if (dist2 < ans) {
                ans = dist2;
            }
        }
    }
    return ans;
}


int main(int argc, char const *argv[]) {
    std::vector<std::complex<int>> input_vec = read_input<int>();
    // int ans_n = find_naive(input_vec);
    // std::cout << "naive: " << ans_n << std::endl;
    int ans_s = find_smart(input_vec);
    std::cout << ans_s << std::endl;
    return 0;
}
