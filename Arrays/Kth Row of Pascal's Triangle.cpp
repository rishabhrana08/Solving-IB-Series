vector<int> Solution::getRow(int A) 
{
vector<vector <int> > vec(A+1);
int i,j;
for(i=0; i<=A; i++) {
    vec[i]= vector<int>(i+1);
} 
for(i=0; i<=A; i++) {
    vec[i][0]=1;
    vec[i][i]=1;
    for(j=1; j<i; j++) {
        vec[i][j]=vec[i-1][j-1]+vec[i-1][j];
    }
}
return vec[A];
}

