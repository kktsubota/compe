#include <iostream>


int main(int argc, char const *argv[])
{
    int R, G, B, N;
    std::cin >> R >> G >> B >> N;
    // max_num
    int n_r = N / R;
    int n_g = N / G;
    int n_b = N / B;
    int ans = 0;

    for (int i = 0; i <= n_r; i++) {
        for (int j = 0; j <= n_g; j++) {
            int num = N - R * i - G * j;
            if (num >= 0 && num % B == 0) {
                ans += 1;
                // std::cout << i << " " << j << " " << num / B << std::endl;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
