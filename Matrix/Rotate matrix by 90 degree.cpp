Naive Approach:
#Last column becomes first row, second last column becomes second row and so on...
void rotateby90(vector<vector<int> >& matrix, int n)
{
  int temp[n][n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      temp[n - j - 1][i] = matrix[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      matrix[i][j] = temp[i][j];
}

Efficient Approach: 
# First find tranpose of matrix and then reverse individual columns
void transpose(vector<vector<int> >&matrix, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      swap(matrix[i][j], matrix[j][i]);
}

void rotateby90(vector<vector<int> >& matrix, int n)
{
  transpose(matrix, n);

  for (int i = 0; i < n; i++)
  {
    int low = 0, high = n - 1;
    while (low < high)
    {
      swap(matrix[low++][i], matrix[high--][i]);
    }

  }
}

TC:O(nxn) AS:O(1)
