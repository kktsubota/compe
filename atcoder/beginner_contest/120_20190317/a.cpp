#include <iostream>

int main(int argc, char const *argv[]) {
    int A, B, C;
    std::cin >> A >> B >> C;
    int limit = B / A;
    std::cout << std::min(limit, C) << std::endl;
    return 0;
}
