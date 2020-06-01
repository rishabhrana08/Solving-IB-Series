void Solution::rotate(vector<vector<int> > &A) {
    
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            int temp=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=temp;
        }  
    }
    for(int i=0;i<A.size();i++)
    {
        int start=0;int end=A.size()-1;
        while(start<end)
        {
            int temp=A[i][start];
            A[i][start]=A[i][end];
            A[i][end]=temp;
            end--;
            start++;
        }  
    }
}

