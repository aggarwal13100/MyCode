#include<bits/stdc++.h>
#define OUT cout<<
#define IN  cin>>
#define MOD 1000000007
#define nitro ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long int ll;
using namespace std;

int main(){ 
  int n;
  cout << "Enter the number of jobs : ";
  cin>>n;

  vector<pair<int, int>>time(n);

  for(int i=0;i<n;i++){
    cin>>time[i].first;
    cin>>time[i].second;
  }
  
  // sort the jobs according to their starting time
  sort(time.begin(),time.end());
  
  int ans=0;

  // making the min heap of jobs of their start time
  priority_queue<int,vector<int>,greater<int>>pq;

  //loop on each job
  int i=0;
  while(i<n)
  {
    //it find the maximum overlap of current job
    //removing all jobs that is compatible with current job
    while((!pq.empty())&&(time[i].first>=pq.top()))
    {
        pq.pop();
    }
    pq.push(time[i].second);
    // updating ans if current job is overlapped with more number of jobs
    ans=max(ans,(int)pq.size());
    i++;
  }
  cout<<ans<<"\n";

  return 0;
}