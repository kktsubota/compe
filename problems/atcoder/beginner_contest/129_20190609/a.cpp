#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int* a;
    *a = 3;
    int* b;
    b = new int(5);
    cout << *a << ", " << *b << "," << endl;
    int* c = new int(10);
    cout << *c << endl;
    return 0;
}
