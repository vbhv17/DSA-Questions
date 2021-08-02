https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/

FOR EACH PLATFORM, We store the departure and arrival times of trains in vector of pairs 
Sort this vector of pairs in increasing order of departure times, since we want to find the MAX trains for which
stoppage can be provided.
Do activity selection problem algorithm for each platform.
We always select the first activity (here train) and then check if further actvities can be selected or not.


int maxStop(int arr[][3])
{
  //vector of pairs to store departure and arrival times of all trains
   vector<pair<int, int>> v[n + 1];

  //making pairs {(departure, arrival)}
   for (int i = 0; i < m; i++) {
      v[arr[i][2]].push_back({arr[i][1], arr[i][0]});
   }

  //sorting the pairs in increasing order of departure times
   for (int i = 0; i < n; i++) {
      sort(v[i].begin(), v[i].end());
   }

   //initializing count = no of platforms since we will provide stoppage to minimum one train on each platform
   int count = n;

  
  //perform activity selection algo for each platform 
   for (int i = 0; i < n; i++) {

      if (v[i].size() == 0)
         continue;

      //x is the current activity which is already chosen
      int x = 0;
     
     
      int j = 1;

      while (j < v[i].size()) {
        
        //checking if jth activity can be chosen
         if (v[i][j].second > v[i][x].first) {
            count++;
           
           //previous chosen activity becomes current activity
            x = j;
            j++;
         }

         else {
            j++;
         }
      }

   }

   return count;
}

TC: O(NLogN)
SC: O(1)
