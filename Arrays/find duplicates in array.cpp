
// solution 1

int Solution::repeatedNumber(const vector<int> &A) {
map<int,int>m;
int n=A.size()-1;
int s=sqrt(n);
int num=n/s+1;
int f=num-1;
for(auto i:A){
    m[(i-1)/s]++;
    if(m[(i-1)/s]>s)f=(i-1)/s;
}
m.clear();
for(auto i:A)
    if(((i-1)/s)==f)m[i]++;
for(auto i:m)
    if(i.second>1)return i.first;
}


//solution 2

int Solution::repeatedNumber(const vector &A) {
int n=A.size();
vector ans(n, 0);
int sol=-1;
for(int i=0; i<n; i++){
ans[A[i]]+=1;
}
for(int i=0; i<n; i++){
if(ans[i]>1){
sol = i;
break;
}
}
return sol;
}


//solution 3


int Solution::repeatedNumber(const vector<int> &A) {
    long long int p=0;
    for(auto i:A)
    p^=i;
    for(int i=1;i<A.size();i++)
    p^=i;
    
    return p;
}


//solution 4

int Solution::repeatedNumber(const vector<int> &A) {
        int n = A.size();
        long long int sum = 0;
        for(int i = 0; i<n; i++){
            sum += A[i];
        }
        long long int m = n-1;
        long long int total = (m * (m+1)) / 2;
        return sum - total;
}
