#include<iostream>
using namespace std;
void sortDates(string dates[],int n){
    // this function sort the dates in format dd-mm-yyyy in chronological order using radix sort
    int order[] = {1,0,4,3,9,8,7,6};
    for(int i:order){
        // maintaing a count array
        int count[10] = {0};
        //maintaining a temp array
        string temp[n];

        for (int j = 0; j < n; j++) {
            count[dates[j][i]-'0']++;
        }
        for (int j = 1; j < 10; j++) {
            count[j] += count[j-1];
        }
        for (int j = n-1; j >= 0 ; j--) {
            count[dates[j][i]-'0']-=1;
            temp[count[dates[j][i]-'0']] = dates[j];
        }
        for (int j = 0; j < n; j++) {
            dates[j] = temp[j];
        }
    }
}
int main(){
    cout << "Enter the number of dates : ";
    int n;
    cin >> n;
    cout << "Enter the dates in format dd-mm-yyyy:" << endl;
    string dates[n];
    for (int i = 0; i < n; i++) {
        cin >> dates[i];
    }
    sortDates(dates,n);

    cout << "Dates in sorted order : "<<endl;
    for (int i = 0; i < n; i++) {
        cout << dates[i] << endl;
    }
    cout << endl;

    return 0;
}