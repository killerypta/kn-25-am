#include <iostream>

using namespace std;

#define ArraySize 30

void copyArray(int source[], int destination[]) {
  for (int i = 0; i < ArraySize; ++i) {
    destination[i] = source[i];
  }
}

void sortArray(int array[], int array_end) {
  for (int i = 0; i < array_end - 1; ++i) {
    for (int j = 0; j < array_end - i - 1; ++j) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  char continuE;

  do {
    int choice, array[ArraySize];
    cout << "[Menu] Array initialization.\n"
         << "[1] Manual enter (30 elements).\n"
         << "[2] Randomize array.\n"
         << "Your choice: ";
    cin >> choice;

    for (int i = 0; i < ArraySize; ++i) {
      if (choice == 1) {
        cout << "[" << i << "/30] << ";
        cin >> array[i];
      } else {
        array[i] = rand() % 100;
        cout << array[i] << " ";
      }
    }

    cout << "\n\n[Task 1] Find sum of 3 largest elements in array. Add this "
            "sum to "
            "each 10-th and subtract it from each 5-th."
         << endl;
    int array_copy[ArraySize];

    copyArray(array, array_copy);
    sortArray(array_copy, ArraySize);

    int sum = array_copy[ArraySize - 1] + array_copy[ArraySize - 2] +
              array_copy[ArraySize - 3];
    cout << "[1/3] Sum of 3 largest elements: " << sum << endl;

    for (int i = 9; i < ArraySize; i += 10) {
      array[i] += sum;
      cout << "\n[2/3] Adding sum to each 10-th element." << endl;
    }

    for (int i = 4; i < ArraySize; i += 5) {
      array[i] -= sum;
      cout << "\n[3/3] Substracting sum from each 5-th element." << endl;
    }
    // Print updated array
    for (int i = 0; i < ArraySize; ++i) {
      cout << array[i] << " ";
    }

    cout << "\n\nCalculate again? [Y/n] ";
    cin >> continuE;

  } while (continuE == 'y' || continuE == 'Y');
  return 0;
}
