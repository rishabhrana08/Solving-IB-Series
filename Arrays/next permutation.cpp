vector<int> Solution::nextPermutation(vector<int> &arr) {
    int n = arr.size();
    bool flag = false;
    for(int i =n-1; i>=1; i--){
        if(arr[i-1] < arr[i]){
            flag = true;
            break;
        }
    }
    if(!flag){
        reverse(arr.begin(), arr.end());
        return arr;
    }
    /*
    Find that point where arr[i-1] < arr[i].
    Now to the right of arr[i-1], find the place number which is just greater than arr[i-1].
    swap these two numbers.
    and reverse element on the right of arr[i-1] (they were already in sorted in descending order);
    */
    for(int i = n-1; i>=1; i--){
        if(arr[i-1] < arr[i]){
            int minElement = arr[i];
            int index = i;
            int j = i;
            for( j = i; j< arr.size();j++ ){
                if(arr[j] > arr[i-1]){
                    if(arr[j] < minElement){
                        minElement = arr[j];
                        index = j;
                    }
                }
            }
            swap(arr[i-1], arr[index]);
            reverse(arr.begin() + i, arr.end());
            break;
        }
    }
    return arr;
}
