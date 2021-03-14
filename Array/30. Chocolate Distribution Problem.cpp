int chocolates(int arr[], int n, int m)
{
  sort(arr,arr+n);

  int i=0;
  int j=m-1;
  int diff=INT_MAX;
  while(j<n)
  {
    diff=min(diff,arr[j]-arr[i]);
    i++;
    j++;
  }

  return diff;
}
