#include <cmath>
#include <iostream>

#define EPS 0.0001

using namespace std;

int main() {
  int choice, Pr;

  // Task selection menu (1 or 2)
  cout << "Choose task to execute:\n"
       << "1. Task 1\n"
       << "2. Task 2\n"
       << "Your choice: ";
  cin >> choice;

  // Input validation
  if (choice < 0 || choice > 2) {
    cout << "Invalid input! Enter number between 0-2." << endl;
    return 0;
  }

  // Main taks menu
  switch (choice) {
  case 1: {
    int i;
    int n = 1;
    double x, u, s;

    // Subtask selection
    do {
      cout << "\nChoose subtask to execute:\n"
           << "1. Calculate the n-th element of the series\n"
           << "2. Calculate the sum of the first n elements\n"
           << "3. Calculate sum of the series with Eps accuracy\n"
           << "0. Exit\n"
           << "Your choice: ";
      cin >> Pr;

      // Subtask menu
      switch (Pr) {
      case 1: {
        cout << "\nEnter value for n (>=0): ";
        cin >> n;

        cout << "\nEnter value for x: ";
        cin >> x;

        // Verify that n not less then 0
        if (n < 0) {
          cout << "\nError! n cannot be less then 0" << endl;
          break;
        }

        i = 1;
        u = x / n;

        for (; i < n; ++i)
          u *= ((x - 1) * i) / ((i + 1) * x);
        cout << "\nn-th element:" << u << endl;
        break;
      }
      case 2: {
        cout << "\nEnter value for n (>=0): ";
        cin >> n;

        cout << "\nEnter value for x: ";
        cin >> x;

        // Verify that n not less then 0
        if (n < 0) {
          cout << "\nError! n cannot be less then 0" << endl;
          break;
        }

        i = 1;
        u = x / n;
        s = 0;
        for (; i <= n; ++i) {
          s += u;
          u *= ((x - 1) * i) / ((i + 1) * x);
        }

        cout << "\nn-th element:" << u << endl;
        break;
      }
      case 3: {
        do {
          cout << "\nEnter value for x: ";
          cin >> x;

          i = 1;
          u = x / n;
          s = 0;
          for (; i <= n; ++i) {
            s += u;
            u *= ((x - 1) * i) / ((i + 1) * x);
          }

          cout << "\nn-th element:" << u << endl;
          break;
        } while (u <= EPS);
      }
      }
    } while (Pr != 0);
  }
  case 2: {
    cout << "Task 2" << endl;

    double x0, xk, dx, a, b, y, x;
    x0 = -3.4;
    xk = -1.4;
    dx = 0.1;
    a = 5;
    b = 4;
    x = 1;

    // for (x = x0; x <= xk; x += dx) {
    //	y = pow(10, -2) * (a + b * x) - exp(pow(x, 3) + b);
    //	cout << "x = " << x << "  y = " << y << "\n" << endl;
    // }

    x = x0;
    while (x <= xk) {
      y = pow(10, -2) * (a + b * x) - exp(pow(x, 3) + b);
      cout << "x = " << x << " y = " << y << endl;
      x += dx;
    }

    cout << "\nEnd of calculations" << endl;
    break;
  }
  default: {
    cout << "Invalid input, try again." << endl;
    return 0;
  }
  }
}
