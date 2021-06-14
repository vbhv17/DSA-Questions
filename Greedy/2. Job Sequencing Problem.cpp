https://www.youtube.com/watch?v=LjPx4wQaRIs&ab_channel=takeUforward


class Solution
{
public:

  static bool comp(Job j1, Job j2)
  {
    return j1.profit > j2.profit;
  }

  //Function to find the maximum profit and the number of jobs done.
  vector<int> JobScheduling(Job arr[], int n)
  {
    sort(arr, arr + n, comp);

    //initializing the deadline
    int maxi = arr[0].dead;

    //finding the maximum deadline
    for (int i = 0; i < n; i++)
      maxi = max(maxi, arr[i].dead);

    //creating an array of size maxi and initializing it to -1
    int result[maxi + 1];
    for (int i = 0; i < maxi + 1; i++)
      result[i] = -1;

    int count = 0, profit = 0;

    //traversing each job
    for (int i = 0; i < n; i++)
    {
      //checking if any job is done at this jobs deadline
      for (int j = arr[i].dead; j >= 1; j--)
      {
        //if no job is done, we do the job, increment count and update profit
        if (result[j] == -1)
        {
          result[j] = arr[i].id;
          count++;
          profit += arr[i].profit;
          break;
        }
      }
    }

    vector<int> ans;
    ans.push_back(count);
    ans.push_back(profit);
    return ans;
  }
};

TC: O(NLogN) + O(N*M)
SC: O(M)
