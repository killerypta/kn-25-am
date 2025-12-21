#include <cmath>
#include <iostream>

using namespace std;

double firstTask(double x, double y, double z);
double secondTask();
void callTask(int n);

/*
 [M] - Menu
 [I] - Input
 [S] - Succesfull
 [E] - Error
 */

int main() {
  int n;

  cout << "[M] Enter number (< 8 || >= 8): ";
  cin >> n;

  callTask(n);

  return 0;
}

double firstTask(double x, double y, double z) {
  return 3 + exp(y - 1) / 1 + pow(x, 2) * fabs(y - tan(z));
}

double secondTask() {
  int x = 0;
  int s = 0;
  int i = 0;

  for (x = 0; x <= 0; ++i) {
    cin >> x;

    if (x > 0) {
      cout << "\n[S] Result: " << s << endl;
    } else {
      if (i % 2 == 0) {
        s += x;
      }
    }
  }

  return s;
}

void callTask(int n) {
  double x, y, z;

  if (n % 15 < 8) {
    cout << "\n[S] Executing first task." << endl;

    cout << "\n[I] Enter value for x, y, z: ";
    cin >> x >> y >> z;

    cout << "\n[S] Result: " << firstTask(x, y, z) << endl;
  } else {
    cout << "\n[S] Executing second task." << endl;

    cout << "\nEnter real numbers (positive - stop): ";

    secondTask();
  }
}
