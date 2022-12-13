#include<iostream>
#include<vector>
using namespace std;

// Connected Components



vector<bool> vis;
int n,m;
vector<vector<int>> adj;
vector<int> components;


int get_comp(int node)
{
    if(vis[node]){
        return 0;
    }
    vis[node]=true;
    int count=1;
    for(auto x:adj[node])
    {
        if(!vis[x])
        {
            count+=get_comp(x);
        }
    }
    return count;
}


int main()
{
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n,false);
    for(int i=0;i<m;i++)
    {   
        //making adjaceny list
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            components.push_back(get_comp(i));
            
        }
    }
    for(auto x:components)
    {
        cout<<x<<" ";
    }
    
    return 0;
}
