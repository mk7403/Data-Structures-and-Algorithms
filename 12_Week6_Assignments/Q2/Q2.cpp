#include <iostream>
using namespace std;
int main()
{
    int a = 7;
    int b = 17;
    int* c = &b;
    *c = 7;
    cout << a << " " << b << endl;    // 7 7
    return 0;
}