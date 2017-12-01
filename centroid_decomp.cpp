#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

#define pb     push_back
#define mp     make_pair
#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin(), v.rend()
#define forc(c,it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
template<typename T, template<typename ELEM, typename ALLOC=std::allocator<ELEM> > class Container>
std::ostream& operator<< (std::ostream& o, const Container<T>& container)
{ typename Container<T>::const_iterator beg = container.begin();
  /*o << "[";*/ while(beg != container.end()) o << " " << *beg++; /*o << " ]";*/ return o; }

const int MOD = 1e9+7;
const int MAX = 1e5+5;
const int LOGN = 20;

int n, m, a, b;
set<int> adj[MAX];
int parent[LOGN][MAX];
int level[MAX];
vector<int> parent_cd(MAX);
vector<int> siz(MAX);
vector<bool> marked(MAX, false);

int dfs1(int s){
	forc(adj[s], it){
		if(*it != parent[0][s]){
			parent[0][*it] = s;
			level[*it] = 1 + level[s];
			dfs1(*it);
		}
	}
}

void pre(){
	level[1] = 1;
	parent[0][1] = 1;
	dfs1(1);
	for(int i = 1 ; i < LOGN ; i++){
		for(int j = 1 ; j <= n ; j++)
			parent[i][j] = parent[i-1][parent[i-1][j]];
	}
}

int lca(int a, int b){
	if(level[a] > level[b]) swap(a, b);
	int diff = level[b] - level[a];

	for(int i = 0 ; i < LOGN ; i++){
		if(diff&(1 << i))
			b = parent[i][b];
	}
	if(b == a)
		return a;

	for(int i = LOGN - 1 ; i >= 0 ; i--){
		if(parent[i][a] != parent[i][b]){
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

int dist(int a, int b){
	return level[a] + level[b] - 2*level[lca(a, b)];
}

int nn;

void dfs2(int s, int p){
	siz[s] = 1;
	nn++;
	forc(adj[s], it){
		if(*it != p){
			dfs2(*it, s);
			siz[s] += siz[*it];
		}
	}
}

int centroid(int s, int p){
	forc(adj[s], it){
		int ch = *it;
		if(ch != p && siz[ch] > (nn/2))
				return centroid(ch, s);
	}
	return s;
}

void decompose(int s, int p){
	nn = 0;
	dfs2(s, s);
	int cent = centroid(s, s);
	
	if(p == -1)
		p = cent;
	
	parent_cd[cent] = p;
	
	forc(adj[cent], it)
	{
		adj[*it].erase(cent);
		decompose(*it,cent);
	}
	adj[cent].clear();
}


int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif
  scanf("%d %d" , &n, &m);
  for(int i = 1 ; i <= m ; i++){
  	scanf("%d %d" , &a, &b);
  	adj[a].insert(b);
  	adj[b].insert(a);
  }
  pre();
  decompose(1, -1);

  
  
  return 0;
}  
