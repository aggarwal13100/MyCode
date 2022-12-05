#include<iostream>
#include<climits>
using std::min;
using std::max;
using std::cout;
using std::cin;
using std::endl;

int FindKthElement(int arr1[],int arr2[],int size1,int size2,int k){
    // This function return the kth element of the sorted array arr1 and arr2
    // having size size1 and size2 respectively
    // For any error it return -1

    // for selecting array (arr1) having lesser element
    if(size1>size2){
        return FindKthElement(arr2,arr1,size2,size1,k);
    }

    //selecting the low and high of first array(arr1)
    //if value of k is higer than the size of larger array
    int low = max(0,k-size2+1);
    if(low>=size1){
        low = size1-1;
    }
    // if value of k is lower than the size of smaller array
    int high = min(size1-1,k);

    while(low<=high){
        int mid1 = low+high>>1;
        int mid2 = k-mid1;

        int l1 = mid1==0 ? INT_MIN : arr1[mid1-1];
        int l2 = mid2==0 ? INT_MIN : arr2[mid2-1];
        int r1 = mid1==size1-1 ? INT_MAX : arr1[mid1];
        int r2 = mid2==size2-1 ?INT_MAX : arr2[mid2];

        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high = mid1-1;
        }
        else{
            low = mid1+1;
        }

    }
    return -1;
}

int main(){
    int size1,size2;
    cout << "Enter the size of array 1 : ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter the elements of the array 1" << endl;
    for(int i=0;i<size1;i++){
        cin >> arr1[i];
    }
    cout << "\nEnter the size of array2 : ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter the elements of the array 2" << endl;
    for(int i=0;i<size2;i++){
        cin >> arr2[i];
    }
    cout << endl;

    int k;

    cout << "Enter the value of k : ";
    cin >> k;

    if(k>=0 && k<=size1+size2-1){
        
        int kthElement = FindKthElement(arr1,arr2,size1,size2,k);

        cout << "Kth Element of both the sorted array is : "<< kthElement << endl;
    }
    else{
        cout << "Enter a legitimate value of k " << endl;
    }

    return 0;
}