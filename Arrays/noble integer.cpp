int Solution::solve(vector<int> &A) 
{
    sort(A.begin(),A.end());
    vector<int> B(A.size());
    B[A.size()-1]=0;int ctr=1;
    for(int i=A.size()-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        {
            if(ctr>1)
            {
                B[i]=B[i+1]+ctr;
                ctr=1;
            }
            else
            {
                B[i]=B[i+1]+1;
            }    
        }
        else if(A[i]==A[i+1])
        {
            ctr++;
            B[i]=B[i+1];
        }
    }
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==B[i])
        {
            return 1;
        }
    }
    return -1;
}

