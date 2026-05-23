#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {10, 25, 30, 45, 50};
    int size = 5;
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = linearSearch(arr, size, target);

    if(result != -1) {
        cout << "Element found at index: " << result;
    } else {
        cout << "Element not found";
    }

    return 0;
}