#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeAndSort(vector<int>& A, const vector<int>& B) {
    // Gabungkan array B ke dalam array A
    A.insert(A.end(), B.begin(), B.end());

    // Urutkan array A
    sort(A.begin(), A.end());
}

int main() {
    vector<int> A = {1, 3, 5, 7};
    vector<int> B = {2, 4, 6, 8};

    cout << "Array A sebelum penggabungan: ";
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Array B sebelum penggabungan: ";
    for (int i : B) {
        cout << i << " ";
    }
    cout << endl;

    mergeAndSort(A, B);

    cout << "Array A setelah penggabungan dan pengurutan: ";
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}