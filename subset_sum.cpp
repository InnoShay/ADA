#include <iostream>
using namespace std;

int arr[20], subset[20], n, target;

// Function to find subsets
void sumOfSubsets(int index, int sum, int size) {

    // If sum becomes equal to target
    if (sum == target) {
        cout << "{ ";
        for (int i = 0; i < size; i++) {
            cout << subset[i] << " ";
        }
        cout << "}\n";
        return;
    }

    // If sum exceeds or no more elements
    if (index == n || sum > target)
        return;

    // Include current element
    subset[size] = arr[index];
    sumOfSubsets(index + 1, sum + arr[index], size + 1);

    // Exclude current element
    sumOfSubsets(index + 1, sum, size);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    cout << "Subsets with sum " << target << ":\n";

    sumOfSubsets(0, 0, 0);

    return 0;
}