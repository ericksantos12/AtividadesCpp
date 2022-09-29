#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x = 10;
    int *px = &x;

    cout << &x; // output: 0x68fef8
    cout << px;
    cout << *px;

    return 0;
}
