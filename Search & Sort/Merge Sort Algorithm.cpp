#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int  l, int  mid, int  h) {

   int i = 0, j = 0, k = l;

   int n = mid - l + 1;
   int m = h - mid;

   int A[n];
   int B[m];

   for (int i = 0; i < n; i++)
      A[i] = arr[i+l];

   for (int j = 0; j < m; j++)
      B[j] = arr[j + mid + 1];

   while (i < n && j < m) {
      if (A[i] <= B[j]) {
         arr[k++] = A[i++];
      }

      else {
         arr[k++] = B[j++];
      }

   }

   while (i < n) {
      arr[k++] = A[i++];
   }

   while (j < m) {
      arr[k++] = B[j++];
   }
}

void MergeSort(int arr[], int  l, int  h) {

   if (l >= h)
      return;

   int mid = (l + h) / 2;

   MergeSort(arr, l, mid);
   MergeSort(arr, mid + 1, h);
   Merge(arr, l, mid, h);
}


int main()
{
   int arr[] = {5,4,3,2,1};

   int n = sizeof(arr) / sizeof(arr[0]);

   MergeSort(arr, 0 , n - 1);

   cout << "The sorted array is" << endl;
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";

   return 0;
}

TC : O(NLogN) ~ Calculated using recurrence relation
