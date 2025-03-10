#include <iostream>
#include <string.h>
using namespace std;

int getLength(char name[])
{
    int length = 0;
    int i = 0;

    while(name[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}
// O(n)

void reverseCharArray(char name[])
{
    int i=0;
    int n = getLength(name);
    int j = n-1;
    while(i <= j)
    {
        swap(name[i], name[j]);
        i++;
        j--;
    }
}
// O(n/2)

int main()
{
    char name[100];
    cin.getline(name, 100);
    cout << "Length is: " << getLength(name) << endl;
    cout << "Length is: " << strlen(name) << endl;
    cout << "Initially: " << name << endl;
    reverseCharArray(name);
    cout << "Reversed: " << name << endl;
    return 0;
}