void Solution::setZeroes(vector<vector<int> > &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int max=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
            if(max<A[i].size())
            {
                max=A[i].size();
            }
    }
    vector<int> B(n+max,1);
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j]==0)
            {
                B[i]=0;
                B[A.size()+j]=0;
            }
        }
    }
    
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(B[i]==0||B[A.size()+j]==0)
            {
               A[i][j]=0 ; 
            }
            else
            A[i][j]=A[i][j];
        }
    }
    
}

