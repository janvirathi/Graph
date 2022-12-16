#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//BFS Traversal of Graph

vector<int> bfsGraph(vector<int> adj[],int n){
    vector<bool> vis(n,false);
    vis[0]=true;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int curr=q.front();
        bfs.push_back(curr);
        q.pop();
        for(auto it: adj[curr]){
            if(!vis[it]){
                vis[it]=true;
                q.push(it);
                
            }
            
        }
    }
    for(int i=0;i<n;i++){
           cout<<bfs[i]<<" "; 
        }
    return bfs;
}



int main(){

int n,m;
//  n=number of nodes
// m=number of edges
cin>>n>>m;


vector<int> adj[n+1];
// creating adjacency list
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
  
  
bfsGraph(adj,n);
    return 0;
}
