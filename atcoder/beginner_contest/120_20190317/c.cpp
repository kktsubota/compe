#include <iostream>
#include <string>


int main() {
  std::string s;
  std::cin >> s;
  int count_0 = 0;
  int count_1 = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      count_0++;
    } else if (s[i] == '1') {
      count_1++;
    }
  }
  std::cout << 2 * std::min(count_0, count_1) << std::endl;
  return 0;
}