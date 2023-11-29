#include<iostream>
using namespace std;
#include<set>
#include<vector>

int getMax(vector<int>& deg){
    // return the index of maximum value
    int maxi = 0;
    for(int i=1 ; i<deg.size() ; i++) {
        if(deg[i]>deg[maxi]){
            maxi = i;
        }
    }
    return maxi;
}

vector<int> vertexCover(int v , vector<pair<int,int>> ed) {
    // return the minimum vertex cover of graph G = <v,ed>
    vector<int> ans;
    vector<int> degree(v,0);
    vector<vector<int>> adj(v);
    set<pair<int,int>> s(ed.begin() , ed.end());

    // making the adjacency matrix "adj" and calculating the degree of each vertex "deg"
    for(int i=0 ; i<ed.size() ;i++) {
        pair<int,int> temp = ed[i];
        adj[temp.first].push_back(temp.second);
        adj[temp.second].push_back(temp.first);
        degree[temp.first]++;
        degree[temp.second]++;
    }
    cout << "deg" << endl;
    for(int i=0 ;i<degree.size() ; i++) {
        cout << degree[i] << " ";
    }
    cout << endl;

    // do until the set of edges is empty
    while(s.size()>0){
        // getting the vertex of maximum degree 
        int maxDegVertex = getMax(degree);
        cout << "max : " << maxDegVertex << endl;

        // putting in the answer and set degree of this vertex to zero
        // so that it cannot be access again
        ans.push_back(maxDegVertex);
        degree[maxDegVertex] = 0;

        // removing the edges connecting to this vertex and reducing the degree by 1 of other connected vertices
        for(int i=0 ; i < adj[maxDegVertex].size() ; i++) {
            degree[adj[maxDegVertex][i]]--;
            s.erase({maxDegVertex,adj[maxDegVertex][i]});
            s.erase({adj[maxDegVertex][i],maxDegVertex});
        }
    }
    return ans;
}

int main(){
    int v,e;
    cout << "Enter the number of vertices" << endl;
    cin >> v;
    cout << "Enter the number of edges" << endl;
    cin >> e;
    cout << "Enter the edges pair" <<endl;

    vector<pair<int,int>> ed;

    for(int i=0 ; i<e ; i++) {
        int a , b;
        cin >> a >> b;
        ed.push_back({a,b});
    }

    vector<int> ans;
    ans = vertexCover(v , ed);
    for(int i=0 ;i<ans.size() ;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

// vertex : 6
// edges : 10
// pair : 0 1 0 2 0 3 0 4 0 5 1 2 1 5 3 2 3 4 4 5

// vertex : 8
// edges : 10
// pair : 0 1 0 4 1 2 1 4 1 5 1 6 2 3 3 6 3 7 4 5

// vertex : 7
// edges : 10
// pair : 0 3 1 2 1 4 1 5 1 6 2 3 2 6 3 4 4 6 5 6 
