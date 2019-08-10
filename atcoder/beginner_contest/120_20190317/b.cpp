#include <iostream>
#include <vector>

int gcd(int A, int B) {
    if (B % A == 0) {
        return A;
    } else {
        return gcd(B % A, B);
    }
}

std::vector<int> enum_div(int n) {
    std::vector<int> ret;
	for(int i=1 ; i <= n ; ++i)
	{
		if(n%i == 0) {
          ret.push_back(i);
		}
	}
	return ret;
}


int main(int argc, char const *argv[])
{
    int A, B, K;
    std::cin >> A >> B >> K;
    int value_max = gcd(std::min(A, B), std::max(A, B));
    std::vector<int> elements = enum_div(value_max);
    int ans = elements[elements.size() - K];
    std::cout << ans << std::endl;

    return 0;
}
