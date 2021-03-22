#we are given with two arrays and their size, we have to find union of these 2 arrays, union will have every distinct element from both the arrays

Naive Approach: We create a temp array of size m+n and copy elements of both array to this temp array and then sort this array and find the count of distinct elements in this array
int doUnion(int a[], int n, int b[], int m)  {
     
      int arr[n+m];
      
      for(int i=0;i<n;i++)
        arr[i]=a[i];
        
      for(int i=0;i<m;i++)
       arr[i+n]=b[i];
       
       sort(arr,(arr+n+m));
       
       int count=1;
       for(int i=1;i<n+m;i++)
        if(arr[i-1]!=arr[i])
          count+=1;
          
        return count;  
       
    }
    TC: O((n+m)log(n+m)) AS: O(n+m)
      
     
 Efficient Approach: Using the idea that both the a=given arrays are sorted, we do something like merge function of merge sort
 # Traverse both array from first index compare both values and print whichever is smaller & increment its pointer 
 # Dont print if element has appeared before (if arr[i] == arr[i-1])
 # If both are equal print either of them
 
 
      
