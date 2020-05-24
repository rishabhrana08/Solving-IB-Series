

//solution 1

bool Solution::hotel(vector &arrive, vector &depart, int K)
{
	int n = arrive.size();			
	int guest = 0;
	sort(arrive.begin(),arrive.end());
	sort(depart.begin(),depart.end());
	for(int i=0,j=0;i<n;i++)
	{
		if(arrive[i]<depart[j])
		{
			guest++;
		}
		else
		{
			j++;
		}
	}
	if(guest>K)
	return 0;

	return 1;
}


//solution 2

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
        
        if(K == 0)
                return false;

        int N = arrive.size();
        
        vector<pair<int, int> > vec;
        for(int i = 0; i < N; ++i) {
            vec.push_back(make_pair(arrive[i], 1));
            vec.push_back(make_pair(depart[i], 0));
        }
         
        sort(vec.begin(), vec.end());
        
        int curActive = 0;
        int maxAns = 0;
        for (int i = 0; i < vec.size(); i++) {
           if (vec[i].second == 1){ 
	        
		// arrival
               
		curActive++;
                maxAns = max(maxAns, curActive);
            } else {
                curActive--;
            }
        }

        if (K >= maxAns) return true;
        return false;
    }


// sollution 3

bool Solution::hotel(vector &arrive, vector &depart, int K)
{
	int n=arrive.size();
	sort(depart.begin(),depart.end());
	sort(arrive.begin(),arrive.end());
	for(int i=0;i<n;i++)
	{
		//Number of events that ended before starting of(i+1)th event

		int l=lower_bound(depart.begin(),depart.end(),arrive[i])-depart.begin();
		if(depart[l]==arrive[i])
		l++;

		//i+1-l is the total number of ongoing events
		
		if(i+1-l>K)
		return 0;
}
return 1;
}
