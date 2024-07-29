#include <iostream>
using namespace std;

void printPattern(int n) {
    int size = 2 * n - 1; 
    int pattern[size][size];  

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int value = min(min(i, j), min(size - i - 1, size - j - 1));
            cout<< n - value;
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    printPattern(n);
    return 0;
}
