vector<int> Solution::maxset(vector<int> &A) 
{
    vector<int> b;
    long long int n=A.size();
    long long int s=0,start=0,sum=0,max=0,len=0,maxlen=0;
    for(int i=0;i<n;i++)
    {
        
        if(A[i]>=0)
        {
            sum+=A[i];  
            len++;
            if(sum>max||((sum>=max)&&len>maxlen))
            {
            max=sum;
            s=start;
            maxlen=len;
            }
        }
        
        else
        {
            start=i+1;
            sum=0;
            len=0;
        }

       
        
    }
    for(int i=s;i<s+maxlen;i++)
    {
        b.push_back(A[i]);
    }
    if(maxlen>0)
    return b;
}

