#include<iostream>


int main() {
    int a;
    std::cin >> a;
    // スペース区切りの整数の入力
    int b,c;
    std::cin >> b >> c;
    // 文字列の入力
    std::string s;
    std::cin >> s;
    // 出力
    std::cout << (a+b+c) << " " << s << std::endl;
    return 0;
}