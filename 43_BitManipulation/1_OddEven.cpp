#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number:" << endl;
    cin >> n;
    if(n&1)
    {
        cout << n << " is odd." << endl;
    }
    else
    {
        cout << n << " is even." << endl;
    }
    return 0;
}