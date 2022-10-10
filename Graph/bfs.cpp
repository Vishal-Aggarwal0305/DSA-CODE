#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int v,vector<int> &ans){ // bfs call for all adjacent nodes ata a time
    vector<int> visited(v,0);
    queue<int> q;
    q.push(0);
    while(q.size()){
        int temp=q.front();
        q.pop();
        ans.push_back(temp);
        visited[temp]=1;
        for(auto &i: adj[temp]){
            if(visited[i]==0) {
                visited[i]=1;
                 q.push(i);
            }
           
        }
    }
    return ;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v]; // adjancy list , n length array containing vector<int>
    for(int i=0;i<e;i++){
        int m,n;
        cin>>m>>n;
        adj[m].push_back(n);
        adj[n].push_back(m);
    }
    vector<int> ans;
    bfs(adj,v,ans);
    for(auto &i: ans) cout<<i<<" ";
    return 0;
}