#include <stdio.h>
int mod=1e9+7;
int inv[301];
struct matrix{int mat[300][300];};
typedef struct matrix matrix;
 
//source:steven and felix:competitive programming 3
matrix mul(matrix a,matrix b,int N) 
{ 
int i,j,k;
matrix c;
for(i=0;i<N;i++)
{
 for(j=0;j<N;j++)
 {
    c.mat[i][j]=0; 
    for(k=0;k<N;k++)
    c.mat[i][j]=((long long)c.mat[i][j]+((long long)a.mat[i][k]*b.mat[k][j])%mod)%mod; 
 }
}
return c;
}
// Without any precomputation
matrix matpow(matrix base,long long p,int N)
{
int i,j;
matrix ans;
for(i=0;i<N;i++)
{
    for(j=0;j<N;j++) ans.mat[i][j]=(i==j);
}
while(p)
{
if (p&1)
ans=mul(ans,base,N);
base=mul(base,base,N);
p>>=1;
}
return ans; 
}

// With precomputation of powers
matrix matpow(matrix base,long long p,int N)
{
int i,j;
matrix ans;
for(i=0;i<N;i++)
{
    for(j=0;j<N;j++) ans.mat[i][j]=(i==j);
}
int count=1;
while(p)
{
if (p&1)
ans=mul(ans,powers[count],N);
count++;
p>>=1;
}
return ans; 
}
void precomp(matrix m,int N)
{
    int i,j;
    for(i=0;i<N;i++)
    {
    for(j=0;j<N;j++) powers[0].mat[i][j]=(i==j);
    }
    for(i=0;i<N;i++)
    {
    for(j=0;j<N;j++) powers[1].mat[i][j]=m.mat[i][j];
    }
    for(i=2;i<=60;i++)
    powers[i]=mul(powers[i-1],powers[i-1],N);
}