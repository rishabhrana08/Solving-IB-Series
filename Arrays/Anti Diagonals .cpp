vector<vector<int> > Solution::diagonal(vector<vector<int> > &A)
{
    vector<vector<int> > answer((A.size() * 2) - 1);

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size() ; j++) 
	{
            answer[i + j].push_back(A[i][j]);
        }
    }
    return answer;
}
