#include <vector>
#include <iostream>


def std::vector<int> get_divisors(int n) {
    std::vector<int> divisors;
    double n_sqrt = std::sqrt((double) n);
    for (int i = 2; i < (int) n_sqrt; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

def int get_min(std::vector<int> v) {
    int value = v[0];
    for (int i = 0; i < v.size(); i++) {
        value = std::min(value, v[i]);
    }
    return value;
}

int main(int argc, char const *argv[]) {
    int N;
    std::cin >> N;
    std::vector<int> As(N);
    for(int i = 0; i < N; i++) {
        std::cin >> As[i];
    }
    int value_min = get_min(As);
    std::vector<int> divisors = get_devisors(N);
    
    int ans = 0;
    for (auto divisor: divisors) {
        for (auto A: As) {
            if (A % divisor)
        }
    }

    return 0;
}
