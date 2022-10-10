#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],int v,vector<int> &ans){ // bfs recursively call any one immediate adjacent node and than go for adjacent node of that immedeiate adjaacent node
    vector<int> visited(v,0); 
    stack<int> s;
    s.push(0); // 0 indexing
    while(s.size()){
        int temp=s.top();
        s.pop();
        ans.push_back(temp);
        visited[temp]=1;
        for(auto &i: adj[temp]){
            if(visited[i]==0) {
                visited[i]=1;
                 s.push(i);
            }
           
        }
    }
    return ;
}

void dfs2(int node ,vector<int> adj[],vector<int> &visited,vector<int> &ans){
 ans.push_back(node);
 visited[node] =1;
 for(auto i : adj[node]){
    if(visited[i]!=1) dfs2(i,adj,visited,ans);
 }

}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int m,n;
        cin>>m>>n;
        adj[m].push_back(n);
        adj[n].push_back(m);
    }
    vector<int> ans;
    
    dfs(adj,v,ans);
    for(auto &i: ans) cout<<i<<" ";
    ans.clear();
    vector<int> visited(v,0);
    dfs2(0,adj,visited,ans);
    cout<<endl;
    for(auto &i: ans) cout<<i<<" ";
    return 0;
}