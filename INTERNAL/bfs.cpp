#include<iostream>
using namespace std;

int adj[10][10], visited[10], n;

void bfs(int start){
    int queue[10], front=0, rear=0;

    queue[rear++]=start;
    visited[start]=1;
    while(front<rear){
        int node=queue[front++];
        cout<<node;
        for (int i=1; i<=n; i++){
            if(adj[node][i]==1 && visited[i]==0){
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}

int main() {
    int start;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    cout << "Enter starting node: ";
    cin >> start;

    // Initialize visited array
    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    cout << "BFS Traversal: ";
    bfs(start);

    return 0;
}