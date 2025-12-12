#include <cmath>
#include <iostream>

using namespace std;

int main() {
  // Task 1.1
  {
    cout << "-- Task 1.1 --\n"
         << "Write a program in C++ for calculating mathematcal expression."
         << endl;

    const double x = 3.87;
    double result;

    result =
        sqrt(fabs(pow(x, 3) + 9)) / sin(fabs(sin(x + pow(x, 3))) + fabs(x));

    cout << "\nInput value: x = " << x << endl;
    cout << "\nResult of calculations: " << result << endl;
  }

  // Task 1.2
  {
    cout << "\n\n-- Task 1.2 --\n"
         << "Calculate the value of the function F. If the denominator is "
            "calculated to be 0, display a message on the screen. The "
            "expressions must be formed using ternary operation and the "
            "conditional operator; using the functions min and max is "
            "prohibited."
         << endl;

    double x, y, z, result;
    float Cmin, Cmax;
    float numerator, denominator;

    cout << "Enter value for x, y, z: ";
    cin >> x >> y >> z;

    Cmin = (x < y + z) ? x : y + z;
    Cmax = (pow(x, 2 > y) ? pow(x, 2) : y);

    numerator = Cmin + exp(x);
    denominator = Cmax + pow(z, 3);

    if (abs(denominator) <= 1E-5) {
      cout << "\nError! Division by 0 impossible." << endl;
    } else {
      result = numerator / denominator;
      cout << "\nResult: " << result << endl;
    }
  }

  // Task 1.3
  {
    cout << "\n\n-- Task 1.3 --\n"
         << "Write a program that determines the region number to which a "
            "point M with given coordinates belongs. Region boundaries should "
            "be assigned to the region with the highest number."
         << endl;

    int N;

    cout << "Enter coordinate X for point M:" << endl;
    float x;
    cin >> x;
    cout << "Enter coordinate Y for point M:" << endl;
    float y;
    cin >> y;

    N = (fabs(x) + fabs(y) < 12) ? N = (y >= 0) ? 1 : 2 : N = (x >= 0) ? 4 : 3;

    cout << "\nPoint M(" << x << "," << y << ") belongs to the area N = " << N
         << endl;
  }

  system("pause");
  return 0;
}
