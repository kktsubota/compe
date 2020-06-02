#include <iostream>
#include <vector>
typedef long long ll; 

int main(int argc, char const *argv[])
{
    int X, Y, Z, K;
    std::cin >> X >> Y >> Z >> K;
    std:vector<ll> As(X);
    std:vector<ll> Bs(X);
    std:vector<ll> Cs(X);
    return 0;
}


# fail because 0 0 0 -> 0 0 1 1 is kept
# for i in range(k):
#     ans = As[idx_1] + Bs[idx_2] + Cs[idx_3]
#     answers.append(ans)

#     diff_1 = INF if x == (idx_1+1) else As[idx_1] - As[idx_1+1]
#     diff_2 = INF if y == (idx_2+1) else Bs[idx_2] - Bs[idx_2+1]
#     diff_3 = INF if z == (idx_3+1) else Cs[idx_3] - Cs[idx_3+1]

#     if diff_1 < diff_2 and diff_1 < diff_3:
#         idx_1 += 1
#     elif diff_2 < diff_1 and diff_2 < diff_3:
#         idx_2 += 1
#     else:
#         idx_3 += 1
