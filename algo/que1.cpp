#include<iostream>
using namespace std;

//merge the partitioning of array
void merge(int arr[],int s,int mid1,int mid2,int e){
    int i = s;
    int j = mid1;
    int k = mid2;

    // temporary array to store the sorted array
    int size = e-s+1;
    int temp[size];
    int index = 0;

    while(i<mid1 && j<mid2 && k<=e){
        if(arr[i]<arr[j]){
            if(arr[i]<arr[k]){
                temp[index++] = arr[i++];
            }
            else{
                temp[index++] = arr[k++];
            }
        }
        else{
            if(arr[j]<arr[k]){
                temp[index++] = arr[j++];
            }
            else{
                temp[index++] = arr[k++];
            }
        }
    }

    //partition 1 and 2 have some elements left
    while(i<mid1 && j<mid2){
        if(arr[i]<arr[j]){
            temp[index++] = arr[i++];
        }
        else{
            temp[index++] = arr[j++];
        }
    }

    //partition 1 and 3 have some elements left
    while(i<mid1 && k<=e){
        if(arr[i]<arr[k]){
            temp[index++] = arr[i++];
        }
        else{
            temp[index++] = arr[k++];
        }
    }

    //partition 2 and 3 have some elements left
    while(j<mid2 && k<=e){
        if(arr[j]<arr[k]){
            temp[index++] = arr[j++];
        }
        else{
            temp[index++] = arr[k++];
        }
    }

    //only one of the partition have some array left
    while(i<mid1){
        temp[index++] = arr[i++];
    }
    while (j<mid2)
    {
        temp[index++] = arr[j++];
    }
    while (k<=e)
    {
        temp[index++] = arr[k++];
    }

    for(int i=0;i<size;i++){
        arr[s+i] = temp[i];
        cout << temp[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[],int s,int e){
    //base condition
    if(e-s+1<=1 || e<=s){
        return ;
    } 

    //partitioning the array in 3 parts
    int size = e-s+1;
    int mid1 = s+(size)/3;
    int mid2 = s+(size*2)/3;

    //recursive calls
    mergeSort(arr,s,mid1-1);
    mergeSort(arr,mid1,mid2-1);
    mergeSort(arr,mid2,e);

    //merge the array
    merge(arr,s,mid1,mid2,e);
}

int main(){
    int e = 24;
    int s =0;
    int arr[e]={3,4,34,8,6,45,344,67,78,25,45,75,3,343,755,32,86,47,86,35,23,15,0,97};
    mergeSort(arr,s,e-1);
    for (int i = 0; i < e; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}