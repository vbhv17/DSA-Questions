Naive: check every possible pair
bool findPair(int arr[], int n, int diff){
    
      for(int i=0;i<n;i++)
      {
          int x = arr[i] + diff;
          for(int j=0; j<n; j++)
          {
              if(arr[j] == x)
              {
                  return true;
              }
          }
      }
      
      return false;
}

Better: Using Hashmap
bool findPair(int arr[], int n, int x){
    
      unordered_map<int,int> mp;
      
      for(int i=0; i<n; i++)
      {
          if(mp.find(arr[i] + x) != mp.end())
          {
              return true;
          }
          
          mp[arr[i]]++;
      }
      
      return -1;
}

Optimal: https://www.youtube.com/watch?v=XGrXiVi7Ces&ab_channel=Pepcoding
bool findPair(int arr[], int n, int target){
    
    sort(arr, arr+n);
    int low=0;
    int high=1;
  
    while(low<n && high<n)
    {
        if(arr[high]-arr[low]==target)
            return true;
            
        else if(arr[high]-arr[low]>target)
            low++;
        
        else
            high++;
    
    }
    return false;
}

TC: O(NLogN)
SC:O(1)
