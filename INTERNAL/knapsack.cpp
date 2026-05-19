#include<iostream>
#include <algorithm>
using namespace std;

struct Item{
    int weight, profit;
    float ratio;
};

int main(){
    int n, capacity;
    cout<<"Enter number of elements ";
    cin>>n;

    Item items[100];
    for (int i=0; i<n; i++){
        cout<<"Enter profit and weight for "<<i+1<<endl;
        cin>>items[i].profit>>items[i].weight;
        items[i].ratio=(float)items[i].profit/items[i].weight;
    }

    cout<<"Enter capacity of knapsack ";
    cin>>capacity;

    for(int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (items[i].ratio<items[j].ratio){
                swap(items[i], items[j]);
            }
        }
    }
    float total_profit=0.0;

    for (int i=0; i<n; i++){
        if (items[i].weight<=capacity){
            total_profit+=items[i].profit;
            capacity-=items[i].weight;
        }
        else{
            total_profit+=items[i].ratio*capacity;
            break;
        }
    }
    cout<<"Maximum Profit: "<<total_profit;
    return 0;


}