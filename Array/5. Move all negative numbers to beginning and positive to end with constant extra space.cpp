Approach 1: Sort the array TC: O(NLogN)  AS: O(1)

Approach 2:Create two arrays for negative and positive numbers and then merge TC: O(N)  AS: O(N)

Approach 3: 2 pointer
void move(int a[], int n)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		if (a[left] > 0 && a[right] < 0)
			swap(a[left++] , a[right--]);
		if (a[left] > 0 && a[right] > 0)
			right--;
		if (a[left] < 0 && a[right] < 0)
			left++;
	}
}

TC: O(N)  AS: O(1)
	
Approach 4: Partition Method Of Quick Sort with Pivot 
void quickSortPartitionwithPivot(int a[], int n)
{
	int pivot = 0;
	int j = -1;
	fon(int i = 0 ; i < n; i++)
	{
		if (a[i] < pivot)
		{
			j++;
			swap(a[i], a[j]);
		}
		else
		{
			continue;
		}
	}
}

TC: O(N)   AS: O(1)
	
