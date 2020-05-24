vector<int> Solution::wave(vector<int> &A)
{
    sort(A.begin(),A.end());
    int a=A.size();
    if(a%2!=0)
    {
        a=a-1;
    }
    for(int i=0;i<a;i+=2)
    {
        swap(A[i],A[i+1]);
    }
    return A;
}
