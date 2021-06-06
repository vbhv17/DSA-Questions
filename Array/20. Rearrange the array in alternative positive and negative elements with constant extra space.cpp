
Approach: https://youtu.be/5MeI5Kk8KTQ?t=493
//Code bu vbhv17

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void rightRotate(int arr[], int from, int to)
{
  int temp = arr[to];
  for (int i = to; i > from; i--)
    arr[i] = arr[i - 1];

  arr[from] = temp;
}


void rearrange(int arr[], int n)
{
  int wrongIndex = -1;

  for (int i = 0; i < n; i++) {

    if (wrongIndex != -1) {
      if ((arr[wrongIndex] > 0 && arr[i] < 1) || (arr[wrongIndex] < 0 && arr[i] > 0))
      {
        rightRotate(arr, wrongIndex, i);

        if (i - wrongIndex >= 2)
          wrongIndex += 2;

        else
          wrongIndex = -1;
      }
    }

    else {
      if ((arr[i] > 0 && i % 2 == 0) || (arr[i] < 0 && i % 2 != 0))
        wrongIndex = i;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  rearrange(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

TC: O(N*N) SC:O(1)
  
  
Efficient Implementation:
We first sort the array in non-increasing order.Then we will count the number of poitive and negative integers.
 Then we will swap the one negative and one positive number till we reach our condition.
BUT, This will rearrange the array elements because we are sorting the array and accessing the element from left to right according to our need.
  
  In this question it is exclusively written that we dont have to change the relative order of elements.
