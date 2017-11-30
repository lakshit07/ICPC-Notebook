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

string text;
string pattern;
int tsize, psize;
int lps[MAX];

void LPS()
{
	lps[0] = 0;
	int len = 0;
	int i = 1;

	while(i < psize)
	{
		if(pattern[len] == pattern[i])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void search()
{
	LPS();
	int i = 0;
	int j = 0;

	while(i < tsize)
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
		}
		
		if(j == psize)
		{
			printf("Pattern found at index %d\n" , i - j);    //text[i-j] to text[i] matched the pattern
			j = lps[j-1];
		}
		else if (i < tsize && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }	
	}
}


int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif

  cin>>text;
  tsize = text.size();
  cin>>pattern;
  psize = pattern.size();

  search();


  return 0;
}  