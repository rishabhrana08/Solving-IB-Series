//solution 1

//complexity o(n! * n)
int Solution::findRank(string A) {
    string s=A;
    int rank=1;
    sort(s.begin(),s.end());
    while(true){
        if (s==A) return rank;
        if(!next_permutation(s.begin(),s.end())){
            break;
        }
        rank++;
        
    }
}



//solution 2

//complexity o(n^2)
#define mod 1000003
int factorial(int n)
{
    if(n<1) return 1;
    else return n*factorial(n-1)%mod;
}
int Solution::findRank(string A) {
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        int count=0;
        for(int j=i+1;j<A.size();j++)
        {
            if(A[i]>A[j])
            {
                count++;
            }
        }
        ans = (ans%mod+count*factorial(A.size()-i-1)%mod)%mod;
    }
    return ans+1;
}


//solution 3

//complexity o(n^2)
#define mod 1000003

int Solution::findRank(string A) {
    int ans=0;
    int n=A.size();
    long long int fact[n];
    fact[0]=1;
    for(int i=1;i<A.size();i++)
    {
        fact[i]=((i%mod)*(fact[i-1]%mod))%mod;
    }
    for(int i=0;i<A.size();i++)
    {
        int count=0;
        for(int j=i+1;j<A.size();j++)
        {
            if(A[i]>A[j])
            {
                count++;
            }
        }
        ans = (ans%mod+count*fact[A.size()-i-1]%mod)%mod;
    }
    return ans+1;
}

//solution 4

//complexity o(n) but not for repeating characters
// A O(n) solution for finding rank of string 
#include <bits/stdc++.h> 
using namespace std; 
#define MAX_CHAR 256 

// A utility function to find factorial of n 
int fact(int n) 
{ 
	return (n <= 1) ? 1 : n * fact(n - 1); 
} 

// Construct a count array where value at every index 
// contains count of smaller characters in whole string 
void populateAndIncreaseCount(int* count, char* str) 
{ 
	int i; 

	for (i = 0; str[i]; ++i) 
		++count[str[i]]; 

	for (i = 1; i < MAX_CHAR; ++i) 
		count[i] += count[i - 1]; 
} 

// Removes a character ch from count[] array 
// constructed by populateAndIncreaseCount() 
void updatecount(int* count, char ch) 
{ 
	int i; 
	for (i = ch; i < MAX_CHAR; ++i) 
		--count[i]; 
} 

// A function to find rank of a string in all permutations 
// of characters 
int findRank(char* str) 
{ 
	int len = strlen(str); 
	int mul = fact(len); 
	int rank = 1, i; 

	// all elements of count[] are initialized with 0 
	int count[MAX_CHAR] = { 0 }; 

	// Populate the count array such that count[i] 
	// contains count of characters which are present 
	// in str and are smaller than i 
	populateAndIncreaseCount(count, str); 

	for (i = 0; i < len; ++i) { 
		mul /= len - i; 

		// count number of chars smaller than str[i] 
		// fron str[i+1] to str[len-1] 
		rank += count[str[i] - 1] * mul; 

		// Reduce count of characters greater than str[i] 
		updatecount(count, str[i]); 
	} 

	return rank; 
} 

// Driver program to test above function 
int main() 
{ 
	char str[] = "string"; 
	cout << findRank(str); 
	return 0; 
} 


