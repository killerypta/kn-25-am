#include <cmath>
#include <iostream>

using namespace std;

double task1(double x, double y, double z);

int main() {
  int n;

  double x, y, z, result;

  cout << "Enter random number: ";
  cin >> n;

  if (n % 15 < 8) {
    cout << "[task 1]\n"
         << "Enter value for x, y, z: ";
    cin >> x >> y >> z;

    result = task1(x, y, z);

    cout << "\nFormula: 3 + exp(y - 1) / 1 + pow(x, 2) * fabs(y - tan(z))\n"
         << "Result: " << result << endl;
  } else {
    int x, s;
    s = 0;

    cout << "[task 2]\n"
         << "Enter real numbers (multiple 2; positive ends calculation): "
         << endl;

    do {
      cin >> x;
      s += x;
      cout << "Sum: " << s << endl;
    } while (x < 0);
  }

  return 0;
}

double task1(double x, double y, double z) {
  return 3 + exp(y - 1) / 1 + pow(x, 2) * fabs(y - tan(z));
}

int task2(int x, int s) {
  do {
    cin >> x;
    if (x % 2) {
      s += x;
      cout << "Current sum: " << s << endl;
    } else {
      cout << "Number dose'nt multple 2!" << endl;
      break;
    }
  } while (x < 0);
  return s;
}
