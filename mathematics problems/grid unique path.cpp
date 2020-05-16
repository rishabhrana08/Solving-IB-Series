
//recursive approach

int Solution::uniquePaths(int A, int B)
{
if(A==B && A==1){
return 1;
}
if(A==1 || B==1){
return 1;
}
return uniquePaths(A-1,B)+uniquePaths(A,B-1);
}


//combinatrics approach

int Solution::uniquePaths(int A, int B)
{
    
    int m=A;int n=B;
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
    long long ans = 1;
    for (int i = n; i < (m + n - 1); i++) {
        ans *= i;
        ans /= (i - n + 1);
    }
    return (int)ans;
}


// dp solution

int Solution::uniquePaths(int A, int B)
{
    int dp[A][B];
    for(int i=0;i<A;i++)
    {
        dp[i][0]=1;
    }
    for(int j=0;j<B;j++)
    {
        dp[0][j]=1;
    }
    for(int i=1;i<A;i++)
    {
        for(int j=1;j<B;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[A-1][B-1];
}

