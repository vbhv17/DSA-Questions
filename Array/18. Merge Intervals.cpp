class Solution {
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals) {

      sort(intervals.begin(), intervals.end());

      vector<vector<int>>  ans;
      int n = intervals.size();
      int a = intervals[0][0];
      int b = intervals[0][1];

      for (int i = 1; i < n; i++) {
         int l = intervals[i][0];
         int r = intervals[i][1];
         if (l > b) {
            ans.push_back({a, b});
            a = l;
            b = r;
         } else {
            b = max(r, b);
            a = min(l, a) ;
         }
      }

      ans.push_back({a, b});
      return ans;
   }
};

TC: O(NlogN) + O(N)
SC: O(N)
