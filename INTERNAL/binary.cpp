#include <iostream>
using namespace std;

// Recursive Binary Search Function
int binarySearch(int arr[], int low, int high, int key) {
    
    // Base condition: element not found
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    // If element found
    if (arr[mid] == key)
        return mid;

    // If key is smaller, search left half
    else if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    // If key is greater, search right half
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}