#include <stdio.h>
int num=359999;
int spf[359999],mob[359999],freq[359999],X[1000];
int mod=1e9+7;
//Ref:https://s3.amazonaws.com/codechef_shared/download/Solutions/LTIME13/Setter/COPRIME3.cpp
void pre()
{
    int i,j;
    for(i=2;i<num;i++)
    {
        if(!spf[i])
        {
            j=i;
            while(j<num)
            {
                if(!spf[j]) spf[j]=i;
                j+=i;
            }
            
        }
    }
    for(i=1;i<num;i++)
    {
        if(i==1) mob[i]=1;
        else if(spf[i/spf[i]]==spf[i]) mob[i]=0;
        else mob[i]=-1*mob[i/spf[i]];
    }
}
int main(void) {
	// your code goes here
	int i,j,k,T,N;
	pre();
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
	    scanf("%d",&N);
	    for(j=0;j<num;j++) freq[j]=0;
	    int zeros=0,ones=0;
	    for(j=0;j<N;j++)scanf("%d",&X[j]);
	    for(j=0;j<N;j++)
	    {
	        for(k=0;k<N;k++)
	        {
	        int temp=((long long)X[j]*X[k])%num;
	        freq[temp]++;
	        if(!temp) zeros++;
	        else if(temp==1) ones++;
	        }
	    }
	    int ans1=0,ans2=0;
	    for(j=1;j<num;j++)
	    {
	        if(!mob[j]) continue;
	        int m=mob[j];
	        k=j;
	        int sum=0;
	        while(k<num)
	        {
	            sum=((long long)sum+freq[k])%mod;
	            k+=j;
	        }
	        int temp=((long long)sum*sum)%mod;
	        int temp2=temp;
	        if(m==-1 && temp)
	        temp2=mod-temp;
	        temp=((long long)temp*sum)%mod;
	        if(m==-1 && temp)
	        temp=mod-temp;
	        ans1=((long long)ans1+temp)%mod;
	        ans2=((long long)ans2+temp2)%mod;
	    }
	    ans2=((long long)ans2*3)%mod;
	    ans2=((long long)ans2*zeros)%mod;
	    int ans3=((long long)zeros*zeros)%mod;
	    ans3=((long long)3*ans3*ones)%mod;
	    int ans=((long long)ans1+ans2+ans3)%mod;
	    printf("%d\n",ans);
	}
	return 0;
}  