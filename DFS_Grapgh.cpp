#include <iostream>
#include <vector>
using namespace std;

//DFS Traversal of Graph

void dfs(int node, vector<int> adj[],vector<bool> &vis,vector<int> &ls){
    vis[node]=true;
    ls.push_back(node);
    // traverse all its neighbours
    for(auto it: adj[node]){
        if(!vis[it]){
            vis[it]=true;
            dfs(it,adj,vis,ls);
        }
    }
}

void dfsGraph(int n, vector<int> adj[]){
    vector<bool> vis(n,false); 
    int node=0;
    vector<int> ls;
    dfs(node,adj,vis,ls);
    for(int i=0;i<ls.size();i++){
        cout<<ls[i]<<" ";
    }
        
    
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
    dfsGraph(n,adj);
    return 0;
}
