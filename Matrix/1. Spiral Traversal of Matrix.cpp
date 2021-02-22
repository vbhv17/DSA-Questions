Approach 1: Maintain 4 pointers top, down, left & bottom and one direction variable
if dir==0 we move from left to right
if dir==1 we move from top to down
if dir==2 we move from right to left
if dir==3 we move from down to top

CODE:
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
	{
		int top = 0, down = r - 1, left = 0, right = c - 1;
		int dir = 0;
		vector<int> ans;
		while(top <= down && left <= right)
		{
			if (dir == 0)
			{
				for (int i = left ; i <= right ; i++ )
				{
					ans.push_back(matrix[top][i]);
				}
				top += 1;
			}
			else if (dir == 1)
			{
				for (int i = top ; i <= down ; i++)
				{
					ans.push_back(matrix[i][right]);
				}
				right -= 1;
			}
			else if (dir == 2)
			{
				for (int i = right ; i >= left ; i--)
				{
					ans.push_back(matrix[down][i]);
				}
				down -= 1;
			}
			else
			{
				for (int i = down ; i >= top ; i--)
				{
					ans.push_back(matrix[i][left]);
				}
				left += 1;
			}
			dir = (dir + 1) % 4;
		}
		return ans;
	}
  
 TC: O(r*c) AS: O(r*c) 
