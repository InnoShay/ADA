#include<iostream>
using namespace std;

int main(){
    int n, source;
    cout<<"Enter number of nodes: ";
    cin>>n;

    int cost[10][10];

    cout<<"Enter cost matrix: ";
    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>>cost[i][j];
            if (cost[i][j]==0 && i!=j){
                cost[i][j]=999;
            }
        }
    }
    cout<<"Enter source node ";
    cin>>source;

    int distance[10], visited[10];

    for (int i=1; i<=n;i++){
        distance[i]=cost[source][i];
        visited[i]=0;
    }

    distance[source]=0;
    visited[source]=1;

    for(int count=1; count<=n; count++){
        int min=999, u;
        for(int i=1; i<=n; i++){
            if (distance[i]<min && visited[i]==0){
                min=distance[i];
                u=i;
            }
        }
        visited[u]=1;
        for (int v=1; v<=n;v++){
            if (visited[v]==0 && (distance[u]+cost[u][v]<distance[v])){
                distance[v]=distance[u]+cost[u][v];
            }
        }

    }
    cout<<"Shortest Distance from node "<<source<< " ";
    for (int i=1; i<=n; i++){
        cout<<"to node"<<i<<"="<<distance[i]<<endl;
    }
    return 0;
}