

//solution 1

int Solution::firstMissingPositive(vector<int> &arr) 
{

	// segregated all positive number from negative and zero
	// negative and zeros are on the right side of the array

	if(!arr.size()) return 1;

	int j=arr.size()-1,ns=0;
	for(int i=arr.size()-1;i>=0;i--)
	{
	    if(arr[i]<=0)
	    {
	        int temp = arr[i];
	        arr[i] = arr[j];
	        arr[j] = temp; 
	        j--;
	        ns++;
	    }
	}

	// size denotes the size of the positive numbers in the array

	int size = arr.size() - ns;
	if(!size) return 1;

	// below code marks negative of the number on an index if that index is present in the array.

	for(int i=0;i<size;i++)
	{
	    if(abs(arr[i])-1 < size && arr[abs(arr[i])-1] > 0)
	        arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
	}

	// first index which is non-negative+1 will be our answer and if all are negative then answer will be size+1.

	for(int i=0;i<size;i++)
	{
	    if(arr[i]>0) return i+1;
	}
		
	return size+1;
}


//solution 2

int firstMissingPositive(vector<int> &A) 
{
      int n = A.size();

      for (int i = 0; i < n; i++) 
      {
          if (A[i] > 0 && A[i] <= n) 
	  {
               int pos = A[i] - 1;
               if (A[pos] != A[i]) 
	       {
                        swap(A[pos], A[i]);
                        i--;
               }
          }
      }
      for (int i = 0; i < n; i++) 
      {
          if (A[i] != i + 1) return (i + 1);
      }
            return n + 1;
}

