#include <cstdlib>
#include <ctime>
#include <iostream>
#include <pthread.h>

using namespace std;

void firstTask();
void secondTask();
void thirdTask();
void fourthTask();
int *fifthTask();

int main() {
  srand(time(0));

  int choice;

  cout << "--- Tasks menu ---\n"
       << "[1] First task\n"
       << "[2] Second task\n"
       << "[3] Third task\n"
       << "[4] Fouth task\n"
       << "[5] Fifth task\n"
       << "Your choice: ";
  cin >> choice;

  switch (choice) {
  case 1:
    firstTask();
    break;
  case 2:
    secondTask();
    break;
  case 3:
    thirdTask();
    break;
  case 4:
    fourthTask();
    break;
  case 5: {
    int *diagonalArray = fifthTask();
    delete[] diagonalArray;
    break;
  }
  case 0: {
    cout << "Exiting..." << endl;
    return 0;
  }
  default: {
    cout << "[Error] Invalid input!" << endl;
    break;
  }
  }
}

void firstTask() {
  cout << "[First task]  Count the number of negative elements with an odd "
          "index in the array. Create a new array and write every third "
          "element of the given array into it."
       << endl;

  int n;
  int choice;

  // Creating First array
  cout << "\n Enter size for new array: ";
  cin >> n;

  int *arr = new int[n];

  // array fill
  cout << "-- choose array fill method --\n"
       << "[1] manual [" << n << "]\n"
       << "[2] auto\n"
       << "your choice: ";
  cin >> choice;

  if (choice < 1 || choice > 2) {
    cout << "[error] incorrect input" << endl;
  }

  for (int i = 0; i < n; ++i) {
    if (choice == 1) {
      cout << "[" << i << "/" << n << "] << ";
      cin >> arr[i];
    } else {
      arr[i] = rand() % 201 + (-100);
    }
  }

  // Calculate amont of negative elements in array
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 != 0 && arr[i] < 0) {
      count += 1;
    }
  }
  cout << "Amount of negative elements in arra: " << count << endl;

  // Create 2-nd array
  int n2 = n / 3;
  int *arr2 = new int[n2];
  int j = 0;

  for (int i = 2; i < n; i += 3) {
    arr2[j] = arr[i];
    ++j;
  }

  // Cout new array
  cout << "New array: ";
  for (int i = 0; i < n2; ++i) {
    cout << arr2[i] << " ";
  }

  // Delete created arrays
  delete[] arr;
  delete[] arr2;
}

void secondTask() {
  cout << "[Second task]  Create two one-dimensional arrays A and B. Build a "
          "new array consisting of elements of array B that do not repeat in "
          "array A."
       << endl;

  int n, n2;
  cout << "Choose first array size: ";
  cin >> n;
  cout << "Choose second array size: ";
  cin >> n2;

  int *arr = new int[n];
  int *arr2 = new int[n2];

  cout << "Filling arrays automatically..." << endl;
  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % 201 + (-100);
  }
  for (int i = 0; i < n2; ++i) {
    arr2[i] = rand() % 201 + (-100);
  }

  // Comparing arrays
  int count = 0;
  for (int i = 0; i < n2; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (arr2[i] == arr[j]) {
        found = true;
        break;
      }
    }
    if (!found) {
      count++;
    }
  }

  int *arr3 = new int[count];
  int k = 0;

  for (int i = 0; i < n2; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (arr2[i] == arr[j]) {
        found = true;
        break;
      }
    }
    if (!found) {
      arr3[k] = arr2[i];
      k++;
    }
  }

  // Cout new array
  cout << "New array: ";
  for (int i = 0; i < k; ++i) {
    cout << arr3[i] << " ";
  }

  // Delete created arrays
  delete[] arr;
  delete[] arr2;
  delete[] arr3;
}

void thirdTask() {
  cout
      << "[Third task] Create two one-dimensional arrays A and B. Build a new "
         "array consisting of elements that belong to both array A and array B."
      << endl;

  int n, n2;
  cout << "Choose first array size: ";
  cin >> n;
  cout << "Choose second array size: ";
  cin >> n2;

  int *arr = new int[n];
  int *arr2 = new int[n2];

  cout << "Filling arrays automatically..." << endl;
  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % 201 + (-100);
  }
  for (int i = 0; i < n2; ++i) {
    arr2[i] = rand() % 201 + (-100);
  }

  // Comparing arrays
  int count = 0;
  for (int i = 0; i < n2; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (arr2[i] == arr[j]) {
        found = true;
        break;
      }
    }
    if (found) {
      count++;
    }
  }

  int *arr3 = new int[count];
  int k = 0;

  for (int i = 0; i < n2; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (arr2[i] == arr[j]) {
        found = true;
        break;
      }
    }
    if (found) {
      arr3[k] = arr2[i];
      k++;
    }
  }

  // Cout new array
  cout << "New array: ";
  for (int i = 0; i < k; ++i) {
    cout << arr3[i] << " ";
  }

  // Delete created arrays
  delete[] arr;
  delete[] arr2;
  delete[] arr3;
}

void fourthTask() {
  cout << "[Fourth task]  Create an array A={aij} of dimension m × n "
          "(specified by the user). Create a function that returns a "
          "one-dimensional array whose elements are equal to the sum of the "
          "largest and smallest elements of each row of array A."
       << endl;

  int m, n;
  cout << "enter matrix size m x n (rows x columns): ";
  cin >> m >> n;

  int **matrix = new int *[m];
  for (int i = 0; i < m; ++i) {
    matrix[i] = new int[n];
  }

  cout << "Filling matrix automatically..." << endl;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      matrix[i][j] = rand() % 201 + (-100);
    }
  }

  int *results = new int[m];

  for (int i = 0; i < m; ++i) {
    int minVal = matrix[i][0];
    int maxVal = matrix[i][0];

    for (int j = 1; j < n; ++j) {
      if (matrix[i][j] < minVal)
        minVal = matrix[i][j];
      if (matrix[i][j] > maxVal)
        maxVal = matrix[i][j];
    }
    results[i] = minVal + maxVal;
    cout << "Row " << i << ": Min + Max = " << results[i] << endl;
  }

  // Delete created matrix and array
  for (int i = 0; i < m; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
  delete[] results;
}

int *fifthTask() {
  cout << "[Fifth task]  Create an array A={aij} of dimension m × n (specified "
          "by the user). Create a function that returns the values of the "
          "diagonal elements of array A."
       << endl;

  int m, n;
  do {
    cout << "enter matrix square size m x n (rows x columns): ";
    cin >> m >> n;
    if (m != n) {
      cout << "[error] matrix does not square (m != n)!" << endl;
    }
  } while (m != n);

  int **matrix = new int *[m];
  for (int i = 0; i < m; ++i) {
    matrix[i] = new int[n];
  }

  cout << "filling matrix automatically..." << endl;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      matrix[i][j] = rand() % 201 + (-100);
    }
  }

  int *arr = new int[m];

  for (int i = 0; i < m; ++i) {
    arr[i] = matrix[i][i];
  }

  cout << "diagonal values: ";
  for (int i = 0; i < m; ++i) {
    cout << arr[i] << " ";
  }

  for (int i = 0; i < m; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return arr;
}
