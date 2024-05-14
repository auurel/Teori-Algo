#include <iostream>

using namespace std;

void selectionSort(int data[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (data[j] < data[minIndex]) {
        minIndex = j;
      }
    }
    swap(data[i], data[minIndex]);
  }
}

void printArray(int data[], int n) {
  for (int i = 0; i < n; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

int main() {
  int data[] = {5, 2, 4, 1, 3};
  int n = sizeof(data) / sizeof(data[0]);

  cout << "Array awal: ";
  printArray(data, n);

  selectionSort(data, n);

  cout << "Array setelah diurutkan: ";
  printArray(data, n);

  return 0;
}