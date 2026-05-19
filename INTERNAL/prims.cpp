#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter cost matrix (0 if no edge):\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> cost[i][j];

            // Replace 0 with infinity
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    int visited[10] = {0};
    int mincost = 0;

    visited[1] = 1;   // Start from node 1

    cout << "\nEdges in MST:\n";

    // Loop until all nodes are included
    for(int k = 1; k < n; k++) {

        int min = 999, a = 0, b = 0;

        // Find minimum edge
        for(int i = 1; i <= n; i++) {
            if(visited[i] == 1) {
                for(int j = 1; j <= n; j++) {
                    if(visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << "Edge: " << a << " - " << b << " Cost: " << min << endl;

        mincost += min;
        visited[b] = 1;   // Include node in MST
    }

    cout << "\nMinimum Cost = " << mincost;

    return 0;
}