string secFrequent (string arr[], int n)
{
   unordered_map<string, int> occ;
   for (int i = 0; i < n; i++)
      occ[arr[i]]++;

   int first_max = INT_MIN, sec_max = INT_MIN;

   for (auto it : occ) {
      if (it.second > first_max) {
         sec_max = first_max;
         first_max = it.second;
      }

      else if (it.second < first_max && it.second > sec_max) {
         sec_max = it.second;
      }
   }

   for (auto it : occ) {
      if (it.second == sec_max) {
         return it.first;
      }
   }
}

TC: O(N)
SC :O(N)
