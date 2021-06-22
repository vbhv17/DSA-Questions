In Fractional Knapsack, we can break items for maximizing the total value of knapsack. 
  This problem in which we can break an item is also called the fractional knapsack problem. 

Checkout link only for concept: https://www.youtube.com/watch?v=IIU646w5rZI&t=4s
Approach : We calculate the value of 1 unit of weight for each weight.
           So that when we have no option but to take fraction, we can multiply this 1 unit value with the remaining weight
           to get the fraction of weight that we should include.
           
//code by vbhv17
class Solution
{
public:
  //Function to get the maximum total value in the knapsack.

  double fractionalKnapsack(int W, Item arr[], int n)
  {
    
    //storing value per unit weight and the index number
    vector<pair<double, int>> v;

    for (int i = 0; i < n; i++)
    {
      //since value and weight are integers we multiply 1.0 to convert them to double to store in ratio
      double ratio = (arr[i].value * 1.0 / arr[i].weight * 1.0);
      v.push_back({ratio, i});
    }

    //sorting do we get the pair with the highest 1 unit value (greedy approach)
    sort(v.begin(), v.end(), greater<pair<double, int>>());

    double ans = 0;
    for (int i = 0; i < n; i++)
    {
      //if current weight is less than total weight W, we can include this whole weight in our ans
      if (arr[v[i].second].weight <= W)
      {
        //decreasing W since we have occupied current weight
        W -= arr[v[i].second].weight;
        ans += arr[v[i].second].value;
      }

      else
      {
        //W < curr weight that means we have to take fraction of current weight
        //v[i].first is val per unit weight, multiplying it with W to get the val we are incrementing
        ans += v[i].first * W * 1.0;
        break;
      }
    }

    return ans;
  }
};

TC:  O(NlogN)
SC: O(N)
