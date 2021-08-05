We have to use BFS here because BFS works in parallel for all the approachable path and so whenever we reach the destination with any path then that
first path will always be minimum. And this is why we have to use BFS as it works in parallel.
And we can not use DFS here because with DFS we will keep on moving in depth till we either reach the destination or we visit all the cells
and no more cells to visit. And so then we will backtrack and then we will try another path and with that another path suppose we are able to 
reach then we can not be sure that this is path is minimum path only. Because DFS does not work in parallel. And so if we are using DFS then we have
to use traverse all the possible paths and then only we can select minimum out of all of them.
But with BFS first path with which we reach destination is always be the minimum path.


We try all 8 possible positions where a Knight can reach from its position. If reachable position is not already visited and is inside the board,
we push this state into queue with distance 1 more than its parent state. Finally we return distance of target position, when it gets pop out from queue.
Below code implements BFS for searching through cells, where each cell contains its coordinate and distance from starting node. In worst case, below code visits all
cells of board, making worst-case time complexity as O(N^2) 

class Solution
{
public:
   // Function to find out minimum steps Knight needs to reach target position.

   void exploreNeighbors(queue<pair<int, int>> &q, int x1, int x2, int d1, int d2, int N, bool &flag, vector<vector<int>> &vis) {

      int cx[] = { -1, -1, 1, 1, 2, 2, -2, -2};
      int cy[] = {2, -2, 2, -2, 1, -1, 1, -1};

      for (int i = 0; i < 8; i++) {
         if ((x1 + cx[i]) < 0 or (x1 + cx[i]) >= N or (x2 + cy[i]) < 0 or (x2 + cy[i]) >= N or vis[x1 + cx[i]][x2 + cy[i]]) {
            continue;
         }

         if ((x1 + cx[i]) == d1 and (x2 + cy[i]) == d2)
         {
            flag = true;
            return;
         }

         q.push({x1 + cx[i], x2 + cy[i]});
         vis[x1 + cx[i]][x2 + cy[i]] = 1;
      }
   }

   int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
   {
      int s1 = KnightPos[0] - 1;
      int s2 = KnightPos[1] - 1;

      int d1 = TargetPos[0] - 1;
      int d2 = TargetPos[1] - 1;

      if (s1 == d1 && s2 == d2)
         return 0;

      vector<vector<int>> vis( N , vector<int> (N));

      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            vis[i][j] = 0;
         }
      }

      queue<pair<int, int>> q;
      q.push({s1, s2});
      vis[s1][s2] = 1;
      int steps = 0;
      int count = q.size();

      bool flag = false;

      while (count > 0) {

         steps++;
         for (int i = 0; i < count; i++) {
            pair<int, int> p1 = q.front();
            int x1 = p1.first;
            int x2 = p1.second;
            q.pop();

            exploreNeighbors(q, x1, x2, d1, d2, N, flag, vis);

            if (flag)
               return steps;
         }

         count = q.size();
      }
      return -1;
   }
};

TC : O(N*N)
SC : O(N*N)
