int Solution::hammingDistance(const vector<int> &A) {
    int mod=1000000007;
    vector<int> binary(32,0);
    
    for(int i=0;i<A.size();i++)
    {   
        int num=A[i];
        int ind=0;
        
        while(num>0)
        {
            binary[ind]+=num&1;
            ind++;
            num=num>>1;
        }
    }
    int ans=0;
    for(int i=0;i<binary.size();i++)
    {
        ans=(ans+2*(binary[i]*(A.size()-binary[i]))%mod)%mod;
    }
    return ans;
}
