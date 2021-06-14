https://www.youtube.com/watch?v=P-6nKM00aTw&ab_channel=AdityaRajiv

Approach: We need the MINIMUM/SMALLEST subset whose sum is greater than the remaining elements
          We sort the array in decreasing order, one by one take elements from the start
          and check if curr_sum becomes greater than sum of remaining elements
          We also keep track of the count of elements which we are including in the subset
          In the end we return this count
          
//code by vbhv17
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int arr[n];
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum += arr[i];
  }

  sort(arr, arr + n, greater<int>());

  int count = 0;
  int curr_sum = 0;

  while (curr_sum <= sum - curr_sum)  //until curr_sum is not greater than remaining sum
  {
    //keep adding more elements in the subset, update curr_sum and count of no of elements taken so far
    curr_sum += arr[count];  
    count++;
  }

  if (curr_sum > sum - curr_sum)  //if our condition is satisfied
  {
    cout << count << endl;        //print the number of elements in the chosen subset
  }

  return 0;
}

TC: O(NLogN)
SC: O(1)
