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

bool visited[MAX] = {false};
bool art[MAX] = {false};
int low[MAX];
int disc[MAX];
int parent[MAX] = {-1};
vector<int> adj[MAX];

bool dfs(int u)
{
	static int tim = 0;
	disc[u] = low[u] = ++tim;
	visited[u] = true;
	int children = 0;

	forc(adj[u] , it)
	{
		if(!visited[*it])
		{
			children++;
			parent[*it] = u;
			bool res = dfs(*it);

      if(res == false)
        return false;

			low[u] = min(low[u] , low[*it]);

			if(parent[u] == -1 && children > 1)
				return false;
			if(parent[u] != -1 && low[*it] >= disc[u] )
				return false;
		}
		else if (*it != parent[u])
			low[u] = min(low[u] , disc[*it]);
	}

  return true;
}

int n , m , u , v;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif

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
  	{
      bool res = dfs(i);
      if(res == false)
      {
        printf("Graph is not biconnected(atleast one not biconnected component");
        return 0;
      }   
    }
  }

  printf("Graph is biconnected");

  

  return 0;
}  