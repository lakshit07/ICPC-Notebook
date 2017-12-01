#include <bits/stdc++.h>
 using namespace std;
typedef long long int ll ;
typedef long double ld;

#define MOD 1000000007ll

#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin(), v.rend()
#define for0(i,n) for(__typeof(n) i = 0; i < n ; i++) 
#define forab(i,a,b) for(__typeof(a) i = a ; i < b ; i++) 
#define forba(i,b,a) for(__typeof(a) i = b ; i > a ; i--) 
#define forc(c,it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define pb     push_back
#define mp     make_pair
#define MAX 100005

int low[MAX];
vector<bool> visited(MAX , false);
int disc[MAX];
stack<pair<int,int> >edge;
int parent[MAX] = {-1};
vector<int> adj[MAX];

void dfs(int u)
{
	static int tim = 0;
	disc[u] = low[u] = ++tim;
	int children = 0;
  visited[u] = true;

	forc(adj[u] , it)
	{
		if(disc[*it] == -1)
		{
			children++;
      edge.push(mp(u , *it));
			parent[*it] = u;
			dfs(*it);

			low[u] = min(low[u] , low[*it]);

			if((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[*it] >= disc[u]))
			{
        while(edge.top().first != u || edge.top().second != *it)
        {
          cout<<edge.top().first<<"-"<<edge.top().second<<endl;
          edge.pop();
        }

        cout<<edge.top().first<<"-"<<edge.top().second<<endl;
        edge.pop();
        cout<<"--------------\n";

       }
		}
		else if (*it != parent[u] && disc[*it] < low[u])
		{
      low[u] = min(low[u] , disc[*it]);
      edge.push(mp(u , *it));
	 }
  }
}

int n , m , u , v;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif

  for0(i , MAX)
  {
    disc[i] = -1;
    low[u] = -1;
  }

  cin>>n>>m;

  for0(i , m)
  {
  	cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }

  for0(i , n)
  {
  	if(!visited[i])
  		dfs(i);
  }

  while(!edge.empty())
  {
    cout<<edge.top().first<<"-"<<edge.top().second<<endl;
    edge.pop();

  }

  return 0;
}  