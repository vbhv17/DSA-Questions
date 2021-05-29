https://practice.geeksforgeeks.org/problems/count-squares3649/1
Naive Solution:
class Solution {
  public:
    int countSquares(int N) {
        // code here
        int count=0;
        int i=1;
        while(i*i<N)
        {
            count++;
            i++;
        }
        
        return count;
    }
};

Solution 2: Square root of N will give us the reqd answer.
  We return ans-1 if ans*ans == N, Since we have to find squares who are less than N

class Solution {
  public:
    int countSquares(int N) {
        
        int ans = sqrt(N);
        if(ans*ans == N)
          return ans-1;
        else
          return ans;
    }
};

