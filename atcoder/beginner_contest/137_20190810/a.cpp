#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void func() {
    throw exception();
}
int main(int argc, char const *argv[]) {
    try {
        func();
    } catch (exception e) {
        
    }
    return 0;
}
