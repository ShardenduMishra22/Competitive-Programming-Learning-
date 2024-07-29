#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // Number of workers
    cin >> n;
    vector<int> masks(n); // Vector to store masks for each worker

    // Reading input and setting masks
    for (int i = 0; i < n; ++i) {
        int num_wrkr; // Number of days the worker works
        cin >> num_wrkr;
        int mask = 0; // Initialize mask to 0
        for (int j = 0; j < num_wrkr; ++j) {
            int day;
            cin >> day;
            mask = mask | (1 << day); // Set the bit corresponding to 'day'
        }
        masks[i] = mask; // Store the mask in the vector
    }

    int max_days = 0; // Maximum number of common days
    int person1 = -1; // Index of first worker
    int person2 = -1; // Index of second worker

    // Finding the pair of workers with the maximum common days
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int intersection = masks[i] & masks[j]; // Intersection of masks
            int common_days = __builtin_popcount(intersection); // Count of common days
            if (common_days > max_days) {
                max_days = common_days;
                person1 = i;
                person2 = j;
            }
        }
    }

    // Output the result
    cout << person1 << " " << person2 << "\n";

    return 0;
}
