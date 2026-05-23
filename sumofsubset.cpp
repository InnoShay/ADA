#include <iostream>
using namespace std;

int arr[100], subset[100];

void solve(int n, int target, int index, int size, int sum) {
    if (sum == target) {
        for (int i = 0; i < size; i++) cout << subset[i] << " ";
        cout << endl;
        return;
    }

    if (index == n || sum > target) return;

    subset[size] = arr[index];
    solve(n, target, index + 1, size + 1, sum + arr[index]);

    solve(n, target, index + 1, size, sum);
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    solve(n, target, 0, 0, 0);

    return 0;
}