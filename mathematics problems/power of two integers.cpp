int Solution::isPower(int A) {
    if(A==1)
    return true;
    for(int i=2;i<A;i++)
    {
        int logAi=log(A)/log(i);
        if(pow(i,logAi)==A)
            return true;
    }
    return false;
}

