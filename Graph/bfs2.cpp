//in bfs we push all adjacent nodes at one time , means they have same value of level, so using bfs we can find level
// if flow is possible(means connected) than level difference will be steps to reach another level

// it also uses for shortest path calculation
//we take a source and udate value of dist if we get less dist from ant other path

#include<bits/stdc++.h>
using namespace std;


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

    vector<int> vis(v,0);
    vector<int> lvl(v,0);

    queue<int> q;
    q.push(0);
    vis[0]=1;

    while(q.size()){
        int node = q.front();
        q.pop();
        cout<<node<< " ";

        for(auto i:adj[node]){
            if(vis[i]==0) {
                q.push(i);
                vis[i]=1;
                lvl[i]=lvl[node]+1;
            }
        }

    }

    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" "<<lvl[i]<<endl;
    }

    return 0;
}

