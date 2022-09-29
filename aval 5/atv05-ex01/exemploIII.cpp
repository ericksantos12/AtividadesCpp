#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x = 10;
    int y = 25;

    int *px = &x;
    int *py = &y;

    cout << (*px) + (*py) << endl;
    return 0;
}
