#include<iostream>
using namespace std;
int rotateAtIndex(int arr[], int n){
    int start = 0;
    int end = n;
    int last = end;


    while (start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]<arr[mid-1]){
            return mid;
        }
        else if(arr[mid]>=arr[last]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {12,7,12,12,12,12};
    int n = sizeof(arr)/sizeof(int)-1;
    int index = rotateAtIndex(arr,n);
    cout << index << endl;
    return 0;
}