https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

Naive Approach: if we closely observe, if we calculate indegree and outdegree of each person then we can notice,
                indegree of a celebrity will be = n-1 (everyone knows him except himself) &&
                outdegree of a celebrity will be 0 (since he doesnt know anyone)
                 
// Algorithm: 
// Create two arrays indegree and outdegree, to store the indegree and outdegree
// Run a nested loop, the outer loop from 0 to n and inner loop from 0 to n.
// For every pair i, j check if i knows j then increase the outdegree of i and indegree of j
// For every pair i, j check if j knows i then increase the outdegree of j and indegree of i
// Run a loop from 0 to n and find the id where the indegree is n-1 and outdegree is 0

class Solution
{
public:
  //Function to find if there is a celebrity in the party or not.
  int celebrity(vector<vector<int> >& M, int n)
  {
    int indegree[n] = {0};
    int outdegree[n] = {0};
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < n; j++) {

        if (M[i][j])
        {
          outdegree[i]++;
          indegree[j]++;
        }
      }
    }
    for (int i = 0; i < n; i++)
      if (outdegree[i] == 0 && indegree[i] == n - 1)
        return i;

    return -1;

  }
};

TC: O(N*N)
SC: O(N)

  

Approach 2: Using Stack
https://www.youtube.com/watch?v=CiiXBvrX-5A&ab_channel=Pepcoding

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
  
Approach 3: Using 2 pointers
Approach: The idea is to use two pointers, one from start and one from the end. Assume the start person is A,
and the end person is B. If A knows B, then A must not be the celebrity. Else, B must not be the celebrity. At the end of the loop, 
only one index will be left as a celebrity. Go through each person again and check whether this is the celebrity. 
The Two Pointer approach can be used where two pointers can be assigned,
one at the start and other at the end and the elements can be compared and the search space can be reduced. 
 
Algorithm : 
Create two indices a and b, where a = 0 and b = n-1
Run a loop until a is less than b.
Check if a knows b, then a can’t be celebrity. so increment a, i.e. a++
Else b cannot be celebrity, so decrement b, i.e. b–
Assign a as the celebrity
Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the number of people whom the celebrity knows. 
  if the count of persons who knows the celebrity is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.
    
class Solution
{
public:
  //Function to find if there is a celebrity in the party or not.
  int celebrity(vector<vector<int> >& M, int n)
  {
    int a = 0;
    int b = n - 1;

    while (a < b) {

      if (M[a][b]) {

        a++;      //if a knows b then we can be sure that a is not a celebrity
      }

      else     //there is a possibility that a is a celebrity
      {
        //checking if a is actually a celebrity
        int knows = 0, isknownby = 0;

        for (int i = 0; i < n; i++) {
          if (M[a][i])
            knows++;
        }

        for (int i = 0; i < n; i++) {

          if (M[i][a])
            isknownby++;
        }

        if (knows == 0 && isknownby == n - 1)
          return a;
        else
          a++;
      }
    }

    return -1;
  }
};

TC: O(N)
SC: O(1)
