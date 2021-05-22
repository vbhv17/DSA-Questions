// Solution 1: Sort the arr and print last k items 
TC: O(NlogN)
  
// Solution 2: Using Max Heap
-> Build a max heap of n items ~ O(N)
-> Take out k items one by one from max heap ~ O(KLogN)
  TC: O(N+KlogN)
    
// Solution 3: Using Min Heap
-> Build a min heap of first k items ~ O(k)
-> Traverse from (k+1)th element  ~ O((n-k)*logk)
    ->Compare the current element with top of heap, if smaller than top, ignore it
    ->Else remove the top element and insert the current element in the min heap
-> Print contents of min heap  ~ O(K)
      
     Overall TC: O(k+(n-k)*logK)
       
Code:
// Note: Here i have used the cp trick to use max heap as a minheap by multiplying -1 to all elements of array and then inserting into maxheap,
// so as to get a minheap eventually, and at last while inserting items into the ans vector we again multiply the elements by -1.
  
  
vector<int> kLargest(int arr[], int n, int k) {

  vector<int> ans;
  priority_queue<int> pq;

  for (int i = 0; i < n; i++)
    arr[i] = -1 * arr[i];

  for (int i = 0; i < k; i++)
    pq.push(arr[i]);

  for (int i = k; i < n; i++)
  {
    if (arr[i] < pq.top())
    {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  for (int i = 0; i < k; i++)
  {
    cout << (-1 * pq.top()) << " ";
    pq.pop();
  }

  return ans;
}
