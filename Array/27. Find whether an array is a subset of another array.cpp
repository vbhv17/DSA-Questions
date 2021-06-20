3 Approaches:
Approach 1: (Naive) Use two loops: The outer loop picks all the elements of arr2[] one by one.
  The inner loop linearly searches for the element picked by the outer loop.
    If all elements are found then return true, else return false.
      
   string isSubset(int a1[], int a2[], int n, int m) {
      
    bool present;
    for(int i=0;i<m;i++)
    {
        present=false;
        for(int j=0;j<n;j++)
        {
            if(a2[i]==a1[j])
            {
              present=true;
              continue; 
            }  
        }
        
        if(present==false)
           return "No";
    }
    return "Yes";
}

TC: O(M*N)
SC: O(1)
  
Approach 2:  Sorting and two pointer
string isSubset(int a1[], int a2[], int n, int m) {
    
   sort(a1, a1+n);
   sort(a2,a2+m);
   
   int i=0;
   int j=0;
   
   while(i<n and j<m)
   {
       if(a1[i]==a2[j])
       {
           i++;
           j++;
       }
       
       else
       {
           i++;
       }
   }
   
   if(i==n and j==m)
     return "Yes";
     
   else if(i==n)
      return "No";
   
   else if(j==m)
     return "Yes";
}

TC: O(NLogN + MLogM)
SC: O(1)

Approach 3: Using hashing
Traverse arr1 and store frequency of every character .
Then traverse arr2 and check if same charater is present in arr1 or not. 
If not present we can return "No" then and there

//code by vbhv17
string isSubset(int a1[], int a2[], int n, int m) {
    
    unordered_map<int, int> mp;
    
    for(int i=0;i<n;i++)
    {
        mp[a1[i]]++;
    }
    
    for(int i=0;i<m;i++)
    {
        if(mp[a2[i]]==0)
          return "No";
    }
    
    return "Yes";

}

TC: O(N+M)
SC: O(N)
