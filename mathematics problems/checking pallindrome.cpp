//solution 1

int Solution::isPalindrome(int x) {
        if(x<0)
            return false;
        if(x==0)
            return true;
        int len = (int)log10(x)+1;
        while(x>0)
        {
            int l = x%10;
            int power = ((int)pow(10,len-1));
            int r = x/power;
            if(l!=r)
                return false;
            x = x%power;
            x = x/10;
            len = len-2;
        }
        return true;
}


//solution 2

int Solution::isPalindrome(int A) {

	string s = to_string(A);

	int l=0,r=s.size()-1;

	while(l<r)
	{
	    if(s.at(l) != s.at(r))return 0;
    
	    l++;r--;
	}

	return 1;
}
