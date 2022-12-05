#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> w;
    cout << "Enter the value of constant : "<<endl;
    int size;
    cin >> size;
    cout << "Enter the value of weights :"<<endl;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        w.push_back(value);
    }

    sort(w.begin(),w.end());
    for(int i=0;i<size/2;i++){
        cout << i << "th friends : " << w[i] << " " << w[size-i-1] <<endl;
    }
    cout << endl;
    return 0;
}