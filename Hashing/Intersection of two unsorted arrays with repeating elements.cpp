https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1#

Naive:
# For every element in first array we check if it has appeared before on the left, if it has not appeared then we check if it is present in second array, increment result if present
 int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
      int ans = 0;
      for (int i = 0; i < n; i++)
      {
        bool flag = false;
        for (int j = 0; j < i; j++)  //check if it has appeared before on the left, is it a repeated element
        {
          if (a[j] == a[i])          //if it has appeared before
          {
            flag = true;
            break;
          }
        }

        if (flag == true)          //if it has appeared before we skip this element
          continue;

        else {
          for (int j = 0; j < m; j++)  // else we check if it is present in the second array
            if (a[i] == b[j]) 
            {
              ans += 1;
              break;
            }

        }
      }
      return ans;
   
   TC: O(nx(n+m))  AS:O(1)
     
   Efficient Solution:  Refer TRACK 1 6:00
   # We create a unordered set for first array to get all the distinct elements of the first array into the set
   # Now we traverse the second array and if we find element ith element of second array present in the set then we increment result and remove this element from the set so that 
   # repeating elements are not counted
     int NumberofElementsInIntersection (int a[], int b[], int n, int m )
  {
    unordered_set<int> s;   
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      s.insert(a[i]);        // it will insert only distinct elements from first array
    }

    for (int j = 0; j < m; j++)
    {
      if (s.find(b[j]) != s.end())  //if element from second array is found in the set
      {
        ans += 1;
        s.erase(b[j]);              //remove this element from the set so that repeating element in second array does not increment the ans
      }
    }

    return ans;
     
   TC:O(n+m) AS:O(n)   
   
   
   
   
   

    
