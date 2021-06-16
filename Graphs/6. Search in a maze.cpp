https://www.youtube.com/watch?v=rKo9MPe0c5A&t=948s

class Solution {
public:
  vector<string> ans;

  void dfsSearch(int i, int j, string s, vector<vector<int>>m, int n, vector<vector<int>> &vis)
  {
    if (i<0 or j<0 or i >= n or j >= n)
      return;

    if (m[i][j] == 0 or vis[i][j] == 1)
      return;

    if (i == n - 1 and j == n - 1) {
      ans.push_back(s);
      return;
    }

    vis[i][j] = 1;

    dfsSearch(i + 1, j, s + 'D', m, n, vis);
    dfsSearch(i, j - 1, s + 'L', m, n, vis);
    dfsSearch(i, j + 1, s + 'R', m, n, vis);
    dfsSearch(i - 1, j, s + 'U', m, n, vis);

    vis[i][j] = 0;
  }

  vector<string> findPath(vector<vector<int>> &m, int n) {

    ans.clear();
    vector<vector<int>> vis(n, vector<int> (n));

    //Base Conditions
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
      return ans;

    string s = "";
    dfsSearch(0, 0, s, m, n, vis);

    return ans;
  }
};

TC: O((N*N)^4)
SC: O(L * X), L = length of the path, X = number of paths
