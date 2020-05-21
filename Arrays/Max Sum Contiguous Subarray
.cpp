int Solution::maxSubArray(const vector<int> &A) {
    int sum=0,max=-2147483648,index;
    if(A.size()==1)
    {
        return A[0];
    }
    for(int i=0;i<A.size();i++)
    {
       sum=sum+A[i];
       if(max<sum)
       {
           max=sum;
       }
       if(sum<0)
       {
           sum=0;
           index=i+1;
       }
       
    }
    return max;
}
