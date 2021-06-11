class Solution {
public:
  int findPosition(int N) {

    int pos = 0;
    int count = 0;
    int ans = 0;
    while (N > 0)
    {
      pos++;             //at every iteration we are one position ahead
      if (N & 1)
      {
        count++;        //counting the number of set bits
        ans = pos;      //if bit is set, we have got a valid position, we update our answer
      }

      N = N >> 1;
    }

    if (count > 1 || count == 0)   //if no if set bits are 0 or greater than one, we return -1
      return -1;
    else
      return ans;
  }
};

TC: O(No of bits in N)
SC: O(1)
