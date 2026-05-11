#include<iostream>
using namespace std;

void maxmin(int arr[], int low, int high, int &max, int &min){
    if (low==high){
        max=min=arr[low];
        return;
    }
    if (high==low+1){
        if(arr[low]<arr[high]){
            max=arr[high];
            min=arr[low];
        }
        else{
            max=arr[low];
            min=arr[high];
        }
        return;
    }
    int mid=(low+high)/2;
    int max1, min1, max2, min2;
    maxmin(arr, low, mid, max1, min1);
    maxmin(arr, mid+1, high, max2, min2);
    
    max=(max1>max2)?max1:max2;
    min=(min1<min2)?min1:min2;
}
int main(){
    int n;
    cout<<"Enter number of elements ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter elements ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int max, min;
    maxmin(arr, 0, n-1, max, min);
    cout<<"Maximum element : "<<max<<endl;
    cout<<"Minimum element : "<<min<<endl;
    return 0;

}