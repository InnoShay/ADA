#include<iostream>
using namespace std;

int arr[20], subset[20], n, target;

void subsetsum(int index, int sum, int size){
    if (sum==target){
        cout<<"{ ";
        for (int i=0; i<size; i++){
            cout<<subset[i]<<" ";
        }
        cout<<"} \n";
        return;
    }
    if (index==n || sum>target){
        return;
    }
    
    subset[size]=arr[index];
    subsetsum(index+1, sum+arr[index], size+1);

    subsetsum(index+1, sum, size);
}
int main(){
    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements ";
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }

    cout<<"Enter target sum: ";
    cin>>target;

    cout<<"Sum of subsets with target : "<<target<<":\n";
    subsetsum(0,0,0);
    return 0;
}
