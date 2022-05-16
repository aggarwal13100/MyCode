// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;
    
    //traversing first window of size 'K'
    for(int i=0;i<K;i++){
        if(A[i]<0){
            //inserting only index of negative elements in deque
            dq.push_back(i);
        }
    }
    //inserting first answer in vector
    //if queue is empty so pushing '0'
    //else pushing first element of queue
    if(!dq.empty()){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    
    for(int i=K;i<N;i++){
        //deletion of element
        //queue should not empty and if front element index - current element
        //is greater than window size then remove it 
        if(!dq.empty() && (i-dq.front())>=K){
            dq.pop_front();
        }
        
        //addition of element
        //if current element is negative than push into queue
        if(A[i]<0){
            dq.push_back(i);
        }
        
        //addition into answer
        if(!dq.empty()){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
 }
