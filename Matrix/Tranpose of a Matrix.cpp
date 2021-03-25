Naive: 
#Create a temp nxn vector and push elements matrix[i,j] to temp[j,i]
# Then copy elements from temp matrix back to original matrix
 
TC:O(nxn)  AS:O(nxn)

Efficient: 
#Swap every (i,j) element with (j,i) except diagonal elements since in transpose, diagonal elements remain at the same position
void transpose(vector<vector<int> >& matrix, int n)
{ 
  for(int i=0;i<n;i++)
     for(int j=i+1;j<n;j++)
        swap(matrix[i][j],matrix[j][i]);      
        
}

TC:O(nxn)  AS:O(1)
