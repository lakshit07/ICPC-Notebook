long long int power(long long int e, long long int n)
{
  long long x=1,p=e;
  while(n)
    {
      if(n&1)
        x = (x*p)%mod;
      p = (p*p)%mod;
      n>>=1;
    }
    return x;
}
