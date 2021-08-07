https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1#
https://www.youtube.com/watch?v=2Sj6-5JFaAo&ab_channel=CodeLibrary

Approach: We have to find the maximum and minimum amount we need to spend inorder to buy all candies given that,
          For every candy that we purchase we would get K candies for free
          So to find minimum amount of money we need to spend to buy all candies,
          We sort the array and start taking one candy from the left of array and for every taken candy we take k candies from the right side
          To get maximum amount of money we take candies from the right side and for every candy taken we take k candies from left          

vector<int> candyStore(int candies[], int N, int K)
{
   int min_sum = 0, max_sum = 0;

   sort(candies, candies + N);

   int i = 0, j = N - 1;

   while (i <= j) {
      min_sum += candies[i];
      i++;
      j -= K;
   }

   i = N - 1;
   j = 0;

   while (i >= j) {
      max_sum += candies[i];
      i--;
      j += K;
   }

   vector<int> v;
   v.push_back(min_sum);
   v.push_back(max_sum);
   return v;
}

TC: O(NLogN)
SC: O(1)
