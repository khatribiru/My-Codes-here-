int Z[MX];
char s[MX];

int func(string s)
{
    int len=s.sz,l=0,r=0,ans=0;
    MEM(Z,0);
    F(i,1,len)
    {
        if(i<=r)
        {
            Z[i]=min(r-i+1,Z[i-l]);
        }
        while(i+Z[i]<len&&s[Z[i]]==s[i+Z[i]])
        {
            ++Z[i];
        }
        if(i+Z[i]-1>r)
        {
            l=i,r=i+Z[i]-1;
        }
    }
    int mx=-1;
    F(i,0,len)
    {
      if(Z[i]<=mx&&(Z[i]+i==len)) ans=max(ans,Z[i]);
      mx=max(Z[i],mx);
    }
    return ans;
}