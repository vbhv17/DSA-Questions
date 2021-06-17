https://www.youtube.com/watch?v=AZ4jEY_JAVc&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=6

#include<bits/stdc++.h>
using namespace std;

void recInsert(vector<int> &arr, int temp)
{
  //Base Condition
  if (arr.size() == 0 || arr[arr.size() - 1] <= temp)
  {
    arr.push_back(temp);
    return;
  }

  int val = arr[arr.size() - 1];
  arr.pop_back();
  recInsert(arr, temp);
  arr.push_back(val);

}

void recSort(vector<int> &arr)
{
  //Base condition
  if (arr.size() == 1)
    return;

  int temp = arr[arr.size() - 1];
  arr.pop_back();
  recSort(arr);

  recInsert(arr, temp);
}


int main() {

  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    arr.push_back(data);
  }

  cout << "Before Sorting" << endl;

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  cout << endl;

  recSort(arr);
  cout << "After Sorting" << endl;

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}
