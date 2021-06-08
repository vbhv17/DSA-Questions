https://www.youtube.com/watch?v=CiiXBvrX-5A&ab_channel=Pepcoding
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

Approach 1: Using Stack
class Solution
{
public:
  //Function to find if there is a celebrity in the party or not.
  int celebrity(vector<vector<int> >& M, int n)
  {
    stack<int> st;
    for (int i = 0; i < n; i++)
      st.push(i);

    while (st.size() >= 2)
    {
      int i = st.top();
      st.pop();
      int j = st.top();
      st.pop();

      if (M[i][j])
        st.push(j);
      else
        st.push(i);
    }

    if (st.empty())
      return -1;

    int x = st.top();

    for (int i = 0; i < n; i++)
      if (M[x][i])
        return -1;

    for (int i = 0; i < n; i++)
    {
      if (i == x)
        continue;

      if (!M[i][x])
        return -1;
    }

    return x;
  }
};

TC:O(N)
SC:O(N)
