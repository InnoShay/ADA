#include<iostream>
using namespace std;

int adj[10][10], visited[10], n;

void dfs(int node){
    cout<<node<< " ";
    visited[node]=1;

    for (int i=1; i<=n; i++){
        if (adj[node][i]==1 and visited[i]==0){
            dfs(i);
        }
    }
}
int main(){
    int start;

    cout<<"Enter number of nodes ";
    cin>>n;

    cout<<"Enter adj matrix ";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>adj[i][j];
        }
    }

    cout<<"Enter starting node";
    cin>>start;

    for(int i=1; i<=n; i++){
        visited[i]=0;
    }

    cout<<"dfs traversal: ";
    dfs(start);
    return 0;
}