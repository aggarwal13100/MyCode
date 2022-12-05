#include<iostream>
using namespace std;

int partition(int arr[],int s , int e){
    // find correct position of pivot element and place there
    // placing all small element to left and all greater element of to right of pivot element

    //taking first element as a pivot element

    int i= e;
    for(int j = e; j>s; j--){
        if(arr[s]<=arr[j]){
            swap(arr[i],arr[j]);
            i--;
        }
    }
    swap(arr[s],arr[i]);
    return i;
}
int quickSelect(int arr[],int s,int e, int k){
    //This function return the value of kth element element in sorted array arr

    // index of pivot element
    int index = partition(arr,s,e);

    // pivot element is the kth element
    if(index==k){
        return arr[index];
    }
    // if index of pivot element is greater than k
    else if(index>k){
        return quickSelect(arr,s,index-1,k);
    }
    // if index of pivot element is less than k
    else{
        return quickSelect(arr,index+1,e,k);
    }
}
int main(){
    int arr[] = {45,56,7,4,3,56,23,97,87,56,3,23,35,56,87,890};
    int s = 0;
    int e = (sizeof(arr)/sizeof(arr[0]))-1;
    cout << "Enter the value of k : ";
    int k;
    cin >> k;
    int ans = quickSelect(arr,s,e,k-1);
    cout << ans <<endl;
    return 0;
}