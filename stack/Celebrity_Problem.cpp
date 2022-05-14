// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

#include<stack>

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        //making a stack pushing all elements
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        
        while(s.size()>1){
            
            //pop out two elements A and B
            int A=s.top();
            s.pop();
            int B=s.top();
            s.pop();
            
            
            // A knows B and B not knows A
            // A can't be celebrity as celebrity do not know anyone
            // So B is potential candidate to be celebrity
            if(M[A][B]==1 && M[B][A]==0){
                s.push(B);
            }
            
            // B knows A and A not knows B
            // So B is potential candidate to be celebrity
            else if(M[A][B]==0 && M[B][A]==1){
                s.push(A);
            }
            
            // Case - Both A and B doesn't know each other
            // OR
            // Case - Both knows each other
            
            // In that Case Both are not Potential Candidate
        }
        
        // If no one is potential candidate return -1
        if(s.empty()){
            return -1;
        }
        else{
            
            //checking canditate person is celebrity or not
            int candidate=s.top();
            int rowCount=0;
            int colCount=0;
            
            // For celebrity all row element is zero
            // And all column element is one except diagonal column
            // row '1' count is zero
            // Column '1' count is n-1
            
            for(int i=0;i<n;i++){
                if(M[candidate][i]==1)
                    rowCount++;
                if(M[i][candidate]==1)
                    colCount++;
            }
            if(rowCount==0 &&colCount==n-1){
                return s.top();
            }
            else{
                return -1;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
