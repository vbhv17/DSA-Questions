https://www.youtube.com/watch?v=50nn3bA1BT4&ab_channel=Pepcoding

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        long long diff=INT_MAX;
        sort(a.begin(), a.end());
        
        //taking the first window of m elements
        int i=0;  
        int j=m-1;
        
        while(j<n)
        {
            //updating the minimum difference encountered so far
            diff=min(diff, a[j]-a[i]);
          
            //increment the window one position ahead
            i++;    
            j++;
        }
        
        return diff;
    }   
};

TC: O(NLogN)
SC: O(1)
