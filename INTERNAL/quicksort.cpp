#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while (true){
        while(i<high && arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
        else{
            break;
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quicksort(int arr[], int low, int high){
    if(low<high){
        int p=partition(arr, low, high);
        quicksort(arr, low, p-1);
        quicksort(arr, p+1, high);
    }
}
int main(){
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;

    int arr[n];

    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    quicksort(arr, 0, n-1);

    cout<<"Sorted array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}