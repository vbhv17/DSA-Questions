https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/
https://www.youtube.com/watch?v=lr5uTrdUQhM&ab_channel=CodeLibrary

Approach: Make a vector of pair of {stock price, ith day}
          Since we want to find the maximum number of stocks, we want to buy the stocks with less prices first
          So we sort the array according to stock price
          Run a loop for N days
          Buy all possible stocks that can be bought on the particular day
          OR buy some less stocks until we have money

int buyMaximumProducts(int n, int k, int price[])
{
   vector<pair<int, int>> v;
   for (int i = 0; i < n; i++) {
      v.push_back({price[i], i + 1});
   }

   sort(v.begin(), v.end());

   int ans = 0;
   for (int i = 0; i < n; i++) {
      int price = v[i].first;
      int stocks = v[i].second;
      if (price * stocks <= k) {
         ans += stocks;
         k -= (price * stocks);
      }

      else {
        
        //the remaining number 
         int rem = k / price;
         ans += rem;
         k -= price * rem;
      }
   }
   return ans;
}

TC: O(NLogN)
SC: O(1)
