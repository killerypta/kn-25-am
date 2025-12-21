#include <iostream>

#define N 30

using namespace std;

void getMax(int a[], int size);

int main() {
  int a[N] = {27, 99, 79, 75, 31, 94, 89, 35, 99, 79, 12, 25, 48, 82, 53,
              22, 58, 64, 90, 60, 66, 85, 31, 9,  40, 89, 36, 37, 98, 40};

  getMax(a, 30);

  return 0;
}

void getMax(int a[], int size) {
  int max = a[0];

  for (int i = 0; i < size; ++i) {
    if (a[i] > max) {
      max = a[i];
    }
    cout << max << endl;
  }
}

// #include <iostream>
//
// using namespace std;
//
// #define N 30
//
// void getMax(int a[], int size);
//
// int main() {
//   int a[N] = {0,   325, 6,   290, 313, 524, 168, 693, 178, 656,
//               886, 946, 575, 702, 460, 669, 864, 99,  468, 493,
//               657, 488, 412, 750, 195, 602, 658, 287, 7,   739};
//
//   getMax(a, 30);
//   return 0;
// }
//
// void getMax(int a[], int size) {
//   int max = a[0];
//
//   for (int i = 0; i < size; ++i) {
//     if (a[i] > max) {
//       max = a[i];
//     }
//     cout << max << endl;
//   }
//   cout << max << endl;
// }
