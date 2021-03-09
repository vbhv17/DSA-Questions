Naive Approach: we take two pointers start and end and traverse the price array until start<end,
                for every ith element we find a greater element on its right and calculate profit by arr[j]-arr[i] 
                and then recursively call for left of i and right of j
                we keep on updating the max_profit
                
int maxProfit(int price[], int start, int end) {

  if (start >= end)
    return 0;

  int profit = 0;
  for (int i = start; i < end; i++)
  {
    for (int j = i + 1; j <= end; j++)
    {
      if (price[j] > price[i])
      {
        int curr_profit = (price[j] - price[i]) + maxProfit(price, start, i - 1) + maxProfit(price, j + 1, end);
        profit = max(profit, curr_profit);

      }
    }
  }

  return profit;
}

TC: O(n*n)   AS:


Efficient Approach: We already know the prices of the stock, so in order to maximize profit, we buy the stock when price
                    hits bottom and we sell when price reaches at peak. we traverse the array and if we find element at ith 
                    position is greater than element on (i-1)th position, we add this difference to our profit.
                    Sum of all such differences will give the max profit we can get (Cumulative profit)

  int maxProfit(int price[], int n) {

  int profit = 0;
  for (int i = 1; i < n; i++)
    if (price[i] > price[i - 1])
      profit += (price[i] - price[i - 1]);

  return profit;
}

TC: O(N)   AS:O(1)
  
  Striver's solution for leetcode variation :- We can buy and sell on one particular day only
  Same concept as max difference between arr[j] and arr[i] where j>i
  
  
  int maxProfit(int prices[], int n) {

  int maxProfit = 0;
  int minPrice = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    minPrice = min(minPrice, prices[i]);
    maxProfit = max(maxProfit, prices[i] - minPrice);

  }

  return maxProfit;
}
  
