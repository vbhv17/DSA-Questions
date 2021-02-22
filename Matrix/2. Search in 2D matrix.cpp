Approach 1: Traverse the whole matrix and compare with target
TC: O(m*n)  AS: O(1)

Approach 2: Staircase Traversal
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
       int i=0,j=matrix[0].size()-1;                  // pointing to top-right element in matrix 
        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                j--;                                  //going left
            else
                i++;                                  //going down
        }
        return false;
    }
};

TC: O(m+n)  AS: O(1)

Approach 3: Copy all elements in a 1-D Array & then do binary search in that array
TC: O(Log(n*m))  AS: O(n*m)

Approach 4: Imaginary Binary Search - Without auxillary array
We are imagining a 1D Matrix in place of 2D as elements are sorted row wise and column wise and then we do binary search in that imaginary 1D Matrix  refer striver's video https://youtu.be/ZYpYur0znng?t=444
    
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size()) return false;            //check for empty matrix
        
        int m=matrix.size();                        //number of rows
        int n=matrix[0].size();                    //number of columns
        
        int low=0;
        int high=(n*m)-1;                
        
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            
            if(matrix[mid/n][mid%n]==target)       //trick for getting row and column number of 2D matrix from index of 1D Matrix
                return true;
            else if(matrix[mid/n][mid%n]>target)
                high=mid-1;
            else
                low=mid+1;     
        }
        return false;
        
    }
};

TC: O(Log(n*m)) AS: O(1)

