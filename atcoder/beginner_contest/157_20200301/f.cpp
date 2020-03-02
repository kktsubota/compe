#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  // intをキーとして扱う集合
  std::set<int> s;

  // 挿入
  s.insert(30);
  s.insert(1);
  s.insert(10);

  s.erase(10);
  for (auto e: s) {
      cout << e << endl;
  }

  return 0;
}
