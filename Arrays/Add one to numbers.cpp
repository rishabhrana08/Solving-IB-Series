vector<int> Solution::plusOne(vector<int> &A) {
int n = A.size();
int x=1;
for(int i=n-1; i>=0;i--)//loop for adding 1 to last digit and carry goes on.
{
int y=A[i]+x;
A[i] = y%10;
x=y/10;
}

if(x!=0)
{
    auto it = A.begin();  //if carry exceeds for cases like 999+1 it pushes 1 at begin.
    A.insert(it,x);
}

while(A[0]==0)
{
    A.erase(A.begin()); //erasing zeroes at first position.
}

return A;
}
