#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
const int MAX=1e5;
int fibo[100001];
int M;
void pre_compute() {
	fibo[0] = 0, fibo[1] = 1;
	for(int i=2; i<=MAX; ++i) {
		fibo[i] = ((long long)fibo[i-1]+fibo[i-2])%M;
	}
}

inline int fib(int &x, int &y, int n) {
	if (n<1e5) {
		x = fibo[n], y = fibo[n+1];
	}
	else {
		int a, b;
		fib(a, b, n >> 1);
		int z = (((long long)b << 1) - a)%M;
		if (z < 0) z += M;
		x =((long long)a*z)%M;
        int t1=((long long)a*a)%M,t2=((long long)b*b)%M;
		y = ((long long)t1+t2)%M;
		if (n & 1) {
			x =((long long)x+y)%M;
			x ^= y ^= x ^= y;
		}
	}
	return x;
}
inline int fibi(int n) {
	int x = 0, y = 1;
	return fib(x, y, n);
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N,i;
    scanf("%d%d",&N,&M);
    int A[N];
    pre_compute();
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);
    int p1,p2,c1,c2;
    p1=fibi(A[0]),p2=fibi(A[0]+1);
    int ans=p2;
    //printf("%d %d\n",p1,p2);
    for(i=1;i<N;i++)
    {  
     int f1=fibi(A[i]),f2=fibi(A[i]-1),f3=((long long)f1+f2)%M;   
     int t1=((long long)f1*p2)%M;
     int t2=((long long)f2*p1)%M;
     //printf("%d%d\n",t1,t2);   
     c1=((long long)t1+t2)%M;
     c1=((long long)c1+f1)%M;   
     t1=((long long)f3*p2)%M;
     t2=((long long)f1*p1)%M;
     c2=((long long)t1+t2)%M;
     c2=((long long)c2+f3)%M;   
     ans=((long long)ans+c2)%M;
     p1=c1;
     p2=c2;  
     //printf("%d\n",ans);   
    }
    ans=((long long)2*ans)%M;
    int t1=(((long long)N*(N+1))/2)%M;
    ans=((long long)ans-t1)%M;
    if(ans<0)ans+=M;
    printf("%d\n",ans);
    return 0;
}

 /*Question:  Define Bib(N) as: Bib(0)=Bib(1)=1
                             Bib(n)=Bib(n-1)+Bib(n-2)+1,n>=2

           Find sigma(Bib(A[i]+A[i+1]+...+A[j])) where 1<=i<=j<=N

 Approach: Bib(n)=2*Fib(n+1)-1 where Fib(0)=0,Fib(1)=1,Fib(n)=Fib(n-1)+Fib(n-2) for n>=2
           If y=A[i] ,then use Fib(x+y)=Fib(y)Fib(x+1)+Fib(y-1)Fib(x)
                           and Fib(x+y+1)=Fib(y+1)Fib(x+1)+Fib(y)Fib(x)
*/
                                                          