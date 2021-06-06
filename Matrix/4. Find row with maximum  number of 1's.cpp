Naive Approach:
//Code by vbhv17

class Solution {
public:
  int rowWithMax1s(vector<vector<int> > arr, int n, int m) {

    int r = 0, c = 0;
    while (r < n && c < m)
    {
      while (r < n)
      {
        if (arr[r][c] == 1)
          return r;

        r++;
      }

      c++;
      r = 0;
    }

    return -1;
  }

};

TC: O(NxM) Worst Case ~ O(N+M) Average Case
SC:O(1)
  
  
Efficient Approach:  https://youtu.be/9bWIWzRFbp8?t=281
class Solution {
public:
  int rowWithMax1s(vector<vector<int> > arr, int n, int m) {

    int ansrow = -1;
    int j = m - 1;

    for (int i = 0; i < n && j >= 0; i++)
    {
      while (j >= 0)
      {
        if (arr[i][j] == 1)
        {
          j--;
          ansrow = i;
        }
        else
        {
          break;
        }
      }
    }
    return ansrow;
  }

};

TC:  O(N+M) SC:O(1)

