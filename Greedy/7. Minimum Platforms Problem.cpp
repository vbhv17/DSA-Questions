https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
https://www.youtube.com/watch?v=eiM8LGi4h_g&t=443s&ab_channel=CodeLibrary

Approach 1: Make a vector of pairs of arrival and departure time of trains
            Sort this vector on the basis of arrival time (since the train which arrives first has to be accomadated first)
            Take a priority queue (min heap) for storing the current trains (store pair of departure time and platform number in it) 
            Push first pair from vector in pq and assign platform 1 to it
            From next train onwards check if arrival time of this train is greater than departure time of train at top of the priority queue  (since we have taken min heap, train with least departure time will be at top)
            IF arrival time of current train is greater than departure time of train at top of pq, then we can accomadate curr train in this platfrom, no need of new platfrom ,
            pop pq top and push departure time of curr train on same platfrom as popped top platform  
            ELSE, push departure time of curr train in queue and assign new platform
            
int findPlatform(int arr[], int dep[], int n)
{
   vector<pair<int, int>>v;
   for (int i = 0; i < n; i++)
   {
      v.push_back({arr[i], dep[i]});
   }

   sort(v.begin(), v.end());

   int p = 1;

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({v[0].second, p});

   for (int i = 1; i < n; i++) {
      int x = pq.top().first; //departure time
      int y = pq.top().second; //platform number

      if (v[i].first > x) {
         pq.pop();
         pq.push({v[i].second, y});
      }

      else {
         pq.push({v[i].second, p + 1});
         p += 1;
      }
   }

   return p;

}

TC: O(NLogN)  SC:O(N)
  
  
 Optimal Solution:  Sort arrival and departure times arrays independently, 
                    We sort arrival time as we want to assign a platform to train which arrives first
                    We sort departure time array independently because every new train which reaches station will search the platform which became 
                    vacant first https://youtu.be/eiM8LGi4h_g?t=595
                    Then we take two pointers i and j
                    i points to arrival time of second train
                    j points to departure time of first train
                    If arrival time of i is greater than departure time of j then we can accomadate this train on the same platform
                    Else we accomadate the train on a new platform, Accodingly increment total platforms reqd
                               
int findPlatform(int arr[], int dep[], int n) {

   sort(arr, arr + n);
   sort(dep, dep + n);

   int pt_no = 1;
   int i = 1, j = 0;
   while (i < n) {
      if (arr[i] > dep[j]) {
         j++;
      }

      else {
         pt_no++;
      }

      i++;
   }

   return pt_no;
}

TC : O(NLogN)
SC : O(1)             
                    
                    
                    
