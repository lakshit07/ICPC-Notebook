#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

#define pb     push_back
#define mp     make_pair
#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin(), v.rend()
#define forc(c,it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
const int MOD = 1e9+7;
const int MAX = 1e5+5;

int n, a, b;
vector<int> adj[MAX];
vector<int> discovery;
int start[MAX], end[MAX];
static int tim = 0;

void dfs(int s, int p){
	discovery.pb(s);
	tim++;
	start[s] = tim;

	forc(adj[s], it){
		if(*it != p)
			dfs(*it, s);
	}
	end[s] = tim;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif

  scanf("%d" , &n);
  for(int i = 0 ; i < n-1 ; i++){
  	scanf("%d %d" , &a, &b);
  	adj[a].pb(b);
  	adj[b].pb(a);
  }
  discovery.pb(-1);
  dfs(1, -1); 
  return 0;
} 