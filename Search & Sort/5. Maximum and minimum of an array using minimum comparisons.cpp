APPROACH 1: Sort the array and return the the first and last elements,
But the number of comparisons required in sorting in the worst case is N(N-1)/2 ~ O(N^2)
  
APPROACH 2: Linear Search 
Initialize values of min and max as minimum and maximum of the first two elements respectively. Starting from 3rd,
compare each element with max and min, and change max and min accordingly
(i.e., if the element is smaller than min then change min, else if the element is greater than max then change max,
 else ignore the element) 

#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int min;
    int max;
};

struct Pair findminmax(int arr[], int n) {

    struct Pair minmax;
    int i = 0;
    if (n == 1) {

        minmax.max = arr[i];
        minmax.min = arr[i];
        return minmax;
    }

    //if array has more than one element
    if (arr[0] > arr[1]) {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }

    else {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }

    for (i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max) {
            minmax.max = arr[i];
        }

        if (arr[i] < minmax.min) {
            minmax.min = arr[i];
        }
    }

    return minmax;
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    struct Pair minmax = findminmax(arr, n);
    cout << "Minimum is " << minmax.min << endl;
    cout << "Maximum is " << minmax.max << endl;
    return 0;
}

In this method, the total number of comparisons is 1 + 2(n-2) in the worst case and 1 + n – 2 in the best case. 
In the above implementation, the worst case occurs when elements are sorted in descending order and the best case occurs when elements are sorted in ascending order

APPROACH 3: Tournament Method (Divide & Conquer)
  Divide the whole array in two parts and find the min and max of left and right subarray, 
  Then compare minimum of left subarray with minimum of right subarray 
  & maximum of left subarray with maximum of right subarray to get the min and max of whole array
  
#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int min;
    int max;
};

struct Pair findminmax(int arr[], int left, int right) {

    struct Pair minmax, mml, mmr;
    int mid;
    if (left == right) {

        minmax.max = arr[left];
        minmax.min = arr[left];
        return minmax;
    }

    if (right == left + 1) {
        if (arr[left] > arr[right]) {
            minmax.max = arr[left];
            minmax.min = arr[right];
        }

        else {
            minmax.max = arr[right];
            minmax.min = arr[left];
        }

        return minmax;
    }

    //if array has more than one element

    mid = (left + right) / 2;
    mml = findminmax(arr, left, mid);
    mmr  = findminmax(arr, mid + 1, right);

    //comparing min and max of mml and mmr
    if (mml.min < mmr.min) {
        minmax.min = mml.min;
    }

    else {
        minmax.min = mmr.min;
    }

    if (mml.max > mmr.max) {
        minmax.max = mml.max;
    }
    else {
        minmax.max = mmr.max;
    }

    return minmax;
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    struct Pair minmax = findminmax(arr, 0, n - 1);
    cout << "Minimum is " << minmax.min << endl;
    cout << "Maximum is " << minmax.max << endl;
    return 0;
}

Total number of comparisons: let the number of comparisons be T(n). T(n) can be written as follows:
T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
T(2) = 1
T(1) = 0
  
APPROACH 4: Compare in pairs
If n is odd then initialize min and max as first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively. 
  
#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int min;
    int max;
};

struct Pair findminmax(int arr[], int n) {

    struct Pair minmax;
    int i = 0;
    if (n & 1) {
        minmax.max = arr[0];
        minmax.min = arr[0];
        i = 1;
    }

    else {
        if (arr[0] > arr[1]) {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }

        else {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }

        i = 2;
    }

    while (i <= n - 2) {

        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > minmax.max) {
                minmax.max = arr[i];
            }

            if (arr[i + 1] < minmax.min) {
                minmax.min = arr[i + 1];
            }
        }

        else {
            if (arr[i] < minmax.min) {
                minmax.min = arr[i];
            }

            if (arr[i + 1] > minmax.max) {
                minmax.max = arr[i + 1];
            }
        }

        i += 2;
    }
    return minmax;
}
int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    struct Pair minmax = findminmax(arr, n);
    cout << "Minimum is " << minmax.min << endl;
    cout << "Maximum is " << minmax.max << endl;
    return 0;
}

Number of Comparisons:
If n is odd:    3*(n-1)/2  
If n is even:   1 Initial comparison for initializing min and max, 
and 3(n-2)/2 comparisons for rest of the elements  =  1 + 3*(n-2)/2 = 3n/2 -2
