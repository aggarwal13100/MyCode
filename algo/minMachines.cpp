#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    cout << "Enter the number of jobs : ";
    int n;
    cin>>n;

    cout << "Enter the jobs start and end time " <<endl;
    vector<int> s(n);
    vector<int> e(n);

    for (int i = 0; i < n; i++) {
        int start,end;
        cin >> start >> end;
        s[i] = start;
        e[i] = end;
    }

    sort(s.begin(),s.end());
    sort(e.begin(),e.end());

    int i=0,j=0;
    int count = 0;
    int maxOverlap = 0;
    while(i<n){
        if(s[i]<=e[j]){
            count++;
            maxOverlap = max(count,maxOverlap);
            i++;
        }
        else{
            count--;
            j++;
        }
    }

    cout << maxOverlap <<endl;

    return 0;
}