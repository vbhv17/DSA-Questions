If a number is a power of two , it will have exactly only one bit set in its binary representation
//code by vbhv17
class Solution {
public:
  // Function to check if given number n is a power of two.
  bool isPowerofTwo(long long n) {

    if (n == 0)             //Base Case
      return false;

    int count = 0;
    while (n > 0)
    {
      n = n & (n - 1);    //Using Brian Kerningans Algorithm to count set bits
      count++;
    }

    if (count > 1)
      return false;
    else
      return true;
  }
};

TC: O(No if set bits in N)   //Brian Kerninghans
SC: O(1)
  
  Simple Solution using Brian Kerninghans //Refer Track
  class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        if(n==0)
           return false; 
        return((n & (n-1)) == 0);
    }
};


