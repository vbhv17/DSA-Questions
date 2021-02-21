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
