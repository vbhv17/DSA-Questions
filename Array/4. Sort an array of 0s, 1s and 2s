
Approach 1: Count number of 0's, 1's & 2's and then create an array of size N and insert 0's then 1's and then 2's

void sort012(int a[], int n){

   int count0=0;
   int count1=0;
   int count2=0;

   for(int i=0 ; i<n ; i++)
   {
     if(a[i]==0)
     counte++;
     else if(a[i]==1)
     count1++;
     else
     count2++;
   }

    for(int i=9 ; i<count0 ; i++)
       a[i]=0;
    for(int i=count0; i<count1 ; i++)
       a[i]=1;
    for(int i=count1; i<count2 ; i++)
       a[i]=2;
}

TC: O(N)  AS: O(N)

Approach 2: DUTCH NATIONAL FLAG ALGORITHM 

void DNF(int a[], int n)
{
	int low = 0, mid = 0, high = (n - 1);
	while (mid <= high)
	{
		if (a[mid] == 0)
		{
			swap(a[low++], a[mid++]);
		}
		else if (a[mid] == 1)
		{
			mid++;
		}
		else
		{
			swap(a[mid], a[high--]);
		}
	}
}

TC: O(N)  AS: O(1)
