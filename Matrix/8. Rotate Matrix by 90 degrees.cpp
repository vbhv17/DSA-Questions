https://leetcode.com/problems/rotate-image/submissions/

Super Naive: (Using Extra Space)
              First row becomes last column, second row becomes second last column and so on,
              Create a temp matrix, copy elements from og matrix to temp mtrix using this idea.
              Copy elements back from temp to og matrix

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
         int n=matrix.size();
         vector<vector<int>> temp;
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                temp[j][n-j-1] = matrix[i][j];   //since first row becomes last column
             }
         }
        
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 matrix[i][j]=temp[i][j];   //copying elements back from temp to original matrix
             }
         }  
    }
};

TC: O(N*N)
SC: O(N*N)
  
Better Solution: Tranpose of a matrix inverts the rows and columns, first row becomes first column, 
                 Second row becomes second column and so on...
                   
         IDEA: We first do tranpose of given matrix so that rows and columns are interchanged after that, 
               we reverse every row of matrix
     https://www.youtube.com/watch?v=Y72QeX0Efxw&ab_channel=takeUforward
     
 class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j], matrix[j][i]);  //finding transpose of matrix
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int left=0;
            int right=n-1;
            while(left<right)
            {
                swap(matrix[i][left], matrix[i][right]);   //reversing individual rows. (CAN ALSO USE REVERSE FUNCTION OF VECTOR)   reverse(matrix[i].begin, matrix[i].end())
                left++;
                right--;
            }
        }
}
};

TC:O(N*N)
SC:O(1)          
