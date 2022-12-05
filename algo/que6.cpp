/***********************************************************
        REPRESENTATION OF GRAPH ADJACENCY LIST
************************************************************/
#include<iostream>
#include<vector>
#include<utility>
#include<climits>
using namespace std;


const int vertices = 5;

class graph{
    public:
    vector<pair<int,int>> adj[vertices];
    void addEdge(int u,int v,int w){
        //This function insert the edge in the graph

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void display(){
        // This function display the graph in adjacency form
        for(int i=0;i<vertices;i++){
            cout << i << " --> ";
            for(auto listElement:adj[i]){
                cout << "(" << listElement.first << " " << listElement.second << ")" << ", ";
            }
            cout << endl;
        }
    }

    int primsAlgorithm(){
        vector<int> key;
        vector<int> parent;
        vector<bool> mst;
        int totalWeight = 0;
        for(int i=0;i<vertices;i++){
            key.push_back(INT_MAX);
            mst.push_back(false);
        }
        key[0] = 0;
        
        for(int i=0;i<vertices;i++){
            //find min value node in key
            int mini = INT_MAX;
            int u ;
            for(int j=0;j<vertices;j++){
                if(mst[j]==false && key[j]<mini){
                    mini = key[j];
                    u=j;
                }
            }
            //mark vertex 'u' as visited
            mst[u] = true;
            totalWeight+=key[u];

            //adjacent node to u update distance in key if not included in mst
            for(auto listElement:adj[u]){
                int node = listElement.first;
                int weight = listElement.second;
                if(mst[node]==false && key[node]>weight){
                    key[node] = weight;
                }
            }
        }
        return totalWeight;
    }

};
int main(){

    graph g;
    cout << "Enter the number of edges : ";
    int n;
    cin>> n;
    
    for (int i = 0; i < n; i++) {
        int u,v,w;
        cout << "Enter edge : ";
        cin >> u>>v>>w;
        g.addEdge(u,v,w);
    }
    g.display();

    cout << endl;

    cout <<g.primsAlgorithm();

    cout <<endl;

    return 0;
}



// 0 1 2 0 3 6 1 3 8 1 4 5 1 2 3 2 4 7