

//solution 1


int Solution::cpFact(int A, int B) {
    if(__gcd(A,B)==1)
    {
        return A;
    }
    else
        while(__gcd(A,B)!=1)
        {
            A=A/__gcd(A,B);			//dividing A by the common divisor of A and B for finding co-prime divisor
        }
    return A;
}



//solution 2



int Solution::cpFact(int A, int B)
{
    for(int i=A;i>=1;i--)
    {
        if((__gcd(B,i)==1) && (A%i==0))
            return i;
    }

}



// solution 3


set<int> getdivisor(int n)
{
        set<int> s;
        for(int i=1 ; i*i<n ; i++)
        {
            if(n%i==0)
            {
                s.insert(i);
                s.insert(n/i);
            }
        }
        return s;
    }

int Solution::cpFact(int A, int B)
{
    set <int> s=getdivisor(A);
    int max=1;
    for(auto a:s)
    {
        if(__gcd(a,B)==1)
        max=a;
    }
    return max;
    

}   


