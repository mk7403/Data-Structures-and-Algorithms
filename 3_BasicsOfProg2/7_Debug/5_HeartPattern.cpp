// Q5. Heart star pattern.

//  e.g., for size=6;
//  ***   ***
// ***** *****
// ***********
//  *********
//   *******
//    *****
//     ***
//      *

// #include <iostream>
// using namespace std;

// int main() {
//   // heart star pattern
//   int size;
//   cin>>size;

//   for (int i = size / 2; i < size; i += 2) {
//     // print first spaces
//     for (int j = 1; j < size - i; j += 2) {
//       cout << " ";
//     }
//     // print first stars
//     for (int j = 0; j < i + 1; j++) {
//       cout << "*";
//     }
//     // print second spaces
//     for (int j = 1; j < size - i + 1; j++) {
//       cout << " ";
//     }
//     // print second stars
//     for (int j = 1; j < i + 1; j++) {
//       cout << "*";
//     }
//     cout << "\n";
//   }
//   // lower part
//   // inverted pyramid
//   for (int i = size; i > 0; i++) {
//     for (int j = 0; j < size - i; j++) {
//       cout << " ";
//     }
//     for (int j = 1; j < i * 2; j++) {
//       cout << "*";
//     }
//     cout << "\n";
//   }
//   return 0;
// }

// SOLUTION
#include <iostream>
using namespace std;

int main() {
  int rows;
  cout<<"Enter the number of rows: ";
  cin>>rows;

  for (int i = rows / 2; i < rows; i += 2) {
    // print first spaces
    for (int j = 1; j < rows - i; j += 2) {
      cout << " ";
    }
    // print first stars
    for (int j = 1; j < i + 1; j++) {
      cout << "*";
    }
    // print second spaces
    for (int j = 1; j < rows - i + 1; j++) {
      cout << " ";
    }
    // print second stars
    for (int j = 1; j < i + 1; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  // lower part
  // inverted pyramid
  for (int i = rows; i > 0; i--) {
    for (int j = 0; j < rows - i; j++) {
      cout << " ";
    }
    for (int j = 1; j < i * 2; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}