Refer GFG Track 
https://www.youtube.com/watch?v=AsbDqOauGZE&ab_channel=CodeLibrary

Solution:
class Solution
{
public:
  //Function to find the maximum number of meetings that can
  //be performed in a meeting room.

  //we sort the activities in increasing order of their end times, so that
  //activity with least end time comes first
  //if end time of two activities are same, we choose the one with least start time
  static bool comp(pair<int, int> p1, pair<int, int> p2)    
  {
    if (p1.second == p2.second)
    {
      return (p1.first < p2.first);
    }

    return (p1.second < p2.second);
  }

  int maxMeetings(int start[], int end[], int n)
  {
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
      v.push_back({start[i], end[i]});
    }

    sort(v.begin(), v.end(), comp);   //custom comparator function

    int ans = 1; //add first activity in solution

    int i = 0; //we have chosen the first activity, i=0 becomes our previous activity

    //j is our current activity, since we have already chosen ith activity,
    //we point j at 1st activity
    int j = 1;

    while (j < n)
    {
      //checking if jth activity overlaps with ith activity or not
      if (v[j].first > v[i].second)
      {
        //if it does not overlap, we can include it in our answer
        ans++;

        //now change the previous and current activity for next iteration
        i = j;
        j++;
      }

      //if it is not a valid activity, we check for next activity
      else {
        j++;
      }
    }

    return ans;
  }
};

TC: O(N)
SC: O(N)
