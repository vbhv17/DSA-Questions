GFG PRACTICE

Naive:
# Traverse all elements and return 1 if current element is equal to X
TC:O(RxC) AS:O(1)
  
Efficient Approach:
#Start from the top right element (or bottom left), if the element is greater than X then move left row wise 
#                                                    if the element is smaller than X move down column wise
#                                                    if the element is equal to X return 1

int matSearch (vector <vector <int>> &mat, int N, int M, int X)
{
  int i = 0, j = M - 1;

  while (i < N && j >= 0)
  {
    if (mat[i][j] == X)
      return 1;

    else if (mat[i][j] > X)
      j -= 1;

    else
      i += 1;
  }
  return 0;
}

TC:O(R+C) AS:O(1)
