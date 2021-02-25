Approach 1:
Naive Solution:

class Solution {
public:
    int setBits(int N) {
        int count = 0;
        while (N > 0)
        {
            if (N & 1)
                count += 1;
            N = N >> 1;
        }
        return count;
    }
};

TC: Theta(Total bits in N)  AS:O(1)
  
  Approach 2:
BRIAN KERNINGAN'S ALGO:
  
  class Solution {
public:
    int setBits(int N) {
        int count = 0;
        while (N > 0)
        {
            N = N & (N - 1);

            count += 1;
        }
        return count;
    }
};

TC: Theta(Count of Set Bit)  AS:O(1)
  
  Approach 3:  Lookup Table Method for 32 Bit number
  *Refer notes & tracks*
