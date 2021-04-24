*Refer notes for explanation*
Naive Approach:

int trappingWater(int arr[], int n) {

    int water = 0;

    for (int i = 1; i < n - 1; i++)
    {
      int lmax = arr[i];
      for (int j = 0; j < i; j++)
        lmax = max(lmax, arr[j]);

      int rmax = arr[i];
      for (int j = i + 1; j < n ; j++)
        rmax = max(rmax, arr[j]);

      water = water + (min(lmax, rmax) - arr[i]);
    }

    return water;
  }

TC: O(N*N)  AS:O(1)
  
  
Approach 2: Pre-compute lmax and rmax:
int trappingWater(int arr[], int n) {

    int water = 0;
    int lmax[n], rmax[n];

    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
      lmax[i] = max(arr[i], lmax[i - 1]);

    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2 ; i >= 0; i--)
      rmax[i] = max(arr[i], rmax[i + 1]);

    for (int i = 1; i < n - 1; i++)
      water = water + (min(lmax[i], rmax[i]) - arr[i]);

    return water;
  }

TC: O(N)  AS:O(N)
  
  
Approach 3: Best Solution:
https://youtu.be/m18Hntz4go8?t=515

