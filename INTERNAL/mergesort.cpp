#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int i=low, j=mid+1, k=low;
    int temp[100];

    while(i<=mid && j<=high){
        if (arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for (int p=low; p<=high; p++){
        arr[p]=temp[p];
    }
}

void mergesort(int arr[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low,mid, high);

    }
}
int main(){
    int n;
    cout<<"Enter number of elements ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr, 0,n-1);
    cout<<"Sorted Array : ";
    for(int i=0; i<n;i++){
        cout<<arr[i];
    }
    return 0;
}