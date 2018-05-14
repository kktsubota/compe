#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> vec1 = {1, 3, 2};
    std::vector<int> vec2 = {4, 10, 3};
    std::vector<bool> vec = vec1 < vec2;
    std::cout << vec.at(0) << std::endl;
    return 0;
}
