#define mod 1000003
long long int power(long long int A,long long int B)
{
    if(A==0) return 0;
    if(B==0) return 1;

    long result;
    
    if(B%2==0)
    {
        result=power(A,B/2);
        return (result*result)%mod;
    }
    else
    {
        result=A%mod;
        return (result * (power(A,B-1))%mod)%mod;
    }
}

int Solution::findRank(string A)
{
    int ans=0;
    int n=A.size();
    long long int fact[n];
    fact[0]=1;
    for(int i=1;i<A.size();i++)
    {
        fact[i]=((i%mod)*(fact[i-1]%mod))%mod;
    }
    for(int i=0;i<A.size();i++)
    {
        int count=0;
        for(int j=i+1;j<A.size();j++)
        {
            if(A[i]>A[j])
            {
                count++;
            }
        }
        
        //store the count of characters in the map for k>=i
        
        map<char,int> m;
        for(int k=i;k<A.size();k++)
        {
            m[A[k]]++;
        }
        long long int d=1;
        for(auto a:m)
        {
            d=((d%mod)*(fact[a.second]%mod))%mod;
        }
        ans = ans+count*(fact[A.size()-i-1]%mod)*power(d,mod-2)%mod;
    }
    return (ans+1)%mod;
}

