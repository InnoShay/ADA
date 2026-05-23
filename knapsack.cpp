#include <iostream>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int value[100], weight[100];
    double ratio[100];

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
        ratio[i] = (double)value[i] / weight[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(value[i], value[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    double totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            totalValue += value[i];
            capacity -= weight[i];
        } else {
            totalValue += ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum value: " << totalValue;

    return 0;
}