#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string checkAnagram() {
    string str1, str2;

    // Input string1
    cout << "Masukkan string pertama: ";
    cin >> str1;

    // Input string2
    cout << "Masukkan string kedua: ";
    cin >> str2;

    if (str1.length() != str2.length()) {
        return "tidak anagram";
    }

    string str1Copy = str1;
    string str2Copy = str2;

    sort(str1Copy.begin(), str1Copy.end());
    sort(str2Copy.begin(), str2Copy.end());

    if (str1Copy == str2Copy) {
        return "anagram";
    } else {
        return "tidak anagram";
    }
}

int main() {
    cout << checkAnagram() << endl;

    return 0;
}