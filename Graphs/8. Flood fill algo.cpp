https://leetcode.com/problems/flood-fill/
https://www.youtube.com/watch?v=ce4vjUVfrhU&ab_channel=CodeLibrary

class Solution {
public:

  void floodFill(vector<vector<int>>& image, int i, int j, int oldColor, int newColor, int n, int m, vector<vector<int>>& vis) {

    if (i<0 or j<0 or i >= n or j >= m)
      return;

    if (vis[i][j] == 1 or image[i][j] != oldColor)
      return;

    vis[i][j] = 1;
    image[i][j] = newColor;

    floodFill(image, i - 1, j, oldColor, newColor, n, m, vis);
    floodFill(image, i, j + 1, oldColor, newColor, n, m, vis);
    floodFill(image, i + 1, j, oldColor, newColor, n, m, vis);
    floodFill(image, i, j - 1, oldColor, newColor, n, m, vis);

  }

  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int oldColor = image[sr][sc];
    floodFill(image, sr, sc, oldColor, newColor, n, m, vis);

    return image;
  }
};
 
TC: O(n*m) ~ No of rows x columns
SC:O(n*m)  ~ For visited matrix
