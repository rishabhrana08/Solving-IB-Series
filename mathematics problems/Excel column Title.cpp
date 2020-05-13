string Solution::convertToTitle(int A) {
    string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans;
    int r;
    while(A>0)
    {
        A=A-1;
        r=A%26;
        ans=s[r]+ans;
        A=A/26;
    }
    return ans;
}

