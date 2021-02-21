Approach 1:
Use linear search 
PseudoCode:

int first = -1, last = -1;
for (int i = 0; i < n; i++)
{
	if (arr[i] != x)
		continue;

	if (first == -1)
		first = i;

	last = i;
}

if (first != -1)
	cout << first << " " << last << endl;

else
	cout << -1 << endl;
  
TC: O(N) AS: O(1)


Approach 2:
Binary Search
Code:
#include <bits/stdc++.h>
using namespace std;
#define ll long long;


int BinarySearch(int a[], int n, int x, int tog) {

	int low = 0, high = n - 1, ans = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (a[mid] < x)
		{
			low = mid + 1;
		}

		else if (a[mid] > x)
		{
			high = mid - 1;
		}

		else
		{
			ans = mid;
			if (tog == -1)
				high = mid + tog;
			else
				low = mid + tog;

		}
	}

	return ans;
}

int main() {

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int x;
		cin >> x;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int first = BinarySearch(a, n, x, -1);
		int last = BinarySearch(a, n, x, 1);

		if (first == -1)
			cout << -1 << endl;
		else
			cout << first << " " << last << endl;
	}
}

TC: O(LogN) AS: O(1)
  
