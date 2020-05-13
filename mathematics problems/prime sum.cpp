int isprime(int b)
{
    if(b==2)
    {
        return 1;
    }
    for(int i=2;i*i<=b;i++)
    {
        if(b%i==0)
        {
            return 0;
        }
    }
    return 1;
}
vector<int> Solution::primesum(int A) {
    vector<int> a;
    for(int i=2;i<A;i++)
    {
        if(isprime(i)&&isprime(A-i))
        {
            a.push_back(i);
            a.push_back(A-i);
            return a;
        }
    
    }

}


