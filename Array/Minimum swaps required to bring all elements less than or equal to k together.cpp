Approach: Count the total elements which are <= K, call them good elements
Now check the number of bad elements in first window of size good
Now slide that window and check the minimum bad elements in window
Update that minimum value in ans


int minSwap(int *arr, int n, int k) {
    
    int good=0;
    int ans = 2147483647;
    int bad = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i]<=k)
          good++;
    }
      
    for(int i=0;i<good;i++){
        if(arr[i]>k){
            bad++;
        }
    }
    
    if(bad==n) return 0;
    
    int j=good-1;
    int i=0;
    while(j<n){
        ans = min(ans, bad);
        j++;
        if(j<n and arr[j]>k) bad++;
        if(arr[i]>k) bad--;
        i++;
    }
    return ans;
}

TC: O(N)
SC: O(1)
