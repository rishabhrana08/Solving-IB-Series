vector<Interval> Solution::merge(vector<Interval> &A)
{
if(A.size()<2)
return A;
sort(A.begin(),A.end(),[](Interval a,Interval b){return a.start<b.start ;});
vector res;
res.push_back(A[0]);
for(int i=1;i<A.size();i++)
{
if(res.back().end<A[i].start) res.push_back(A[i]);
else
res.back().end=max(res.back().end,A[i].end);
}
return res;
}

