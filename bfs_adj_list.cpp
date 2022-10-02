#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;
// from the starting node 
vector<int> bfs(vector<int> v[], int s, int start)
{
    queue<int> q;
   map<int , bool> explored;
   cout<<0<<" ";
  q.push(0);
  vector<int> ans;
    while (!q.empty())
    {
        int current = q.front();
        explored[current] = true;
        for (int i = 0; i <v[current].size(); i++)
        {
            if (explored[v[current][i]] == false)
            {
                ans.push_back(v[current][i]);
                explored[v[current][i]] = true;
                q.push(v[current][i]);
            }
        }
        q.pop();
    }
    
    return ans;
}
int main()
{
    int n,m;
    cin>>m>>n;
	vector<int> v[n+1];
    for(int i=0;i<m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	v[a].push_back(b);
    	v[b].push_back(a);
    }

    int start;
    cin>>start;

    vector<int> ans=bfs(v,n+1, start);
    for(int i=0;i<n;i++)
     cout<<ans[i]<<" ";
	return 0;
}


5 4
0 1 
0 2
0 3 
2 4