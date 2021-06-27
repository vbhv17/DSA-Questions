https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

Naive Solution: 2 Nested for loops TC:O(N^2)
  
Optimal Solution: Using Merge Sort 
Modifying merge sort a bit so it returns count of inversions
https://www.youtube.com/watch?v=kQ1mJlwW-c0&t=733s&ab_channel=takeUforward
https://www.youtube.com/watch?v=sV4RhDIIKO0&t=414s&ab_channel=ApnaCollege

Start refering code from bottom
class Solution {
public:
    
    long long merge(long long arr[], long long l, long long mid, long long r)
    {
        long long count = 0;

        long long n1 = mid - l + 1;
        long long n2 = r - mid;

        long long a[n1];
        long long b[n2];

        for (int i = 0; i < n1; i++)
            a[i] = arr[l + i];

        for (int i = 0; i < n2; i++)
            b[i] = arr[mid + i + 1];

        long long i = 0, j = 0, k = l;
        long long inv;
        while (i < n1 && j < n2)
        {
            if (a[i] <= b[j]) {
                arr[k] = a[i];
                i++;
                k++;
            }

            else {
                arr[k] = b[j];
                count += n1 - i;
                j++;
                k++;
            }

        }

        while (i < n1) {
            arr[k] = a[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = b[j];
            k++;
            j++;
        }

        return count;
    }


    long long mergeSort(long long arr[], long long l, long long r)
    {
        long long count = 0;

        if (l < r) {

            long long mid = (l + r) / 2;
            count += mergeSort(arr, l, mid);
            count += mergeSort(arr, mid + 1, r);
            count += merge(arr, l, mid, r);
        }

        return count;
    }
 
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long ans = mergeSort(arr, 0, N - 1);
        return ans;
    }

};

TC: O(NLogN)
SC: O(N)
