Approach 1: Traverse the whole matrix and compare with target
TC: O(m*n)  AS: O(1)

Approach 2: Staircase Traversal
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
       int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                j--;
            else
                i++;
        }
        return false;
    }
};

TC: O(m+n)  AS: O(1)

Approach 3: Copy all elements in a 1-D Array & then do binary search in that array
TC: O(Log(n*m))  AS: O(n*m)

Approach 4: Imaginary Binary Search - Without auxillary array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size()) return false;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int low=0;
        int high=(n*m)-1;
        
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            
            if(matrix[mid/n][mid%n]==target)
                return true;
            else if(matrix[mid/n][mid%n]>target)
                high=mid-1;
            else
                low=mid+1;     
        }
        return false;
        
    }
};

TC: O(m+n)  AS: O(1)

