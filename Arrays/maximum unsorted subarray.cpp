
//solution 1

vector<int> Solution::subUnsort(vector<int> &A) {
int n = A.size();
vector<int> ans;
int start = -1, end = -1;
// if we look at end variable then its the last index where things are not sorted
// i.e its the last index where A[i] < maxValue of left array
// after this A[i] >= maxValue of left array so sorted :slight_smile:
// so we consider the elements from start and keep cnahging the end value
// if we encounter index where A[i] < maxValue of left array
int maxi = A[0];
for(int i = 1; i < n; i++){
if(A[i] < maxi) end = i;
maxi = max(maxi, A[i]);
}
// at this point if end has not got a value other than -1 we know array is sorted
if(end == -1)
{
ans.push_back(-1);
return ans;
}
// now we try to find start index so its the first index before which everything is sorted
// i.e first index where A[i] > minValue of right array
// before this A[i] < minValue of right array so sorted :slight_smile:
// so we consier the elements from end and keep changing the start value
// if we encounter index where A[i] > minValue of right array
int mini = A[n-1];
for(int i = n-1; i >= 0; i--){
if(A[i] > mini) start = i;
mini = min(mini, A[i]);
}
ans.push_back(start);
ans.push_back(end);
return ans;
}



//solution 2

vector<int> Solution::subUnsort(vector<int> &A) {
    int mnind = -1, mn;
    int mxind = -1, mx;
    for (int i = 0; i < A.size() - 1; i++)
        if (A[i] > A[i + 1])
        {
            mnind = i;
            mn = A[i + 1];
            break;
        }
    if (mnind < 0)
        return vector<int>{mnind};
    mx = mn;
    for (int i = mnind; i < A.size() - 1; i++)
        if (A[i] > A[i + 1])
        {
            mxind = i;
            mx = max(mx, A[i]);
            mn = min(mn, A[i + 1]);
        }
    int fin = -1;
    for (int i = mxind + 1; i < A.size(); i++)
        if (A[i] >= mx)
        {
            fin = i - 1;
            break;
        }
    if (fin ==-1)
        fin =  A.size() - 1;
    int st = mnind;
    for (int i = mnind; i > -1; i--)
        if (A[i] > mn)
            st = i;
    return vector<int>{st, fin};
}


// solution 3


vector<int> Solution::subUnsort(vector<int> &A) {

int lef = -1,rig=-1;
int temp = A[0];
for ( int i=1; i<A.size(); i++ ){
    if ( A[i]<temp ) rig = i;
    temp = max(temp,A[i]);
}
temp = A[A.size()-1];
for ( int i=A.size()-1; i>=0; i-- ){
    if ( temp<A[i] ) lef = i;
    temp = min(temp,A[i]);
}
if ( lef == -1 ) return {-1};
else return {lef,rig};
}
