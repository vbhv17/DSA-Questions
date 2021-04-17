=> Refer notes
class Solution{
  public:
    /*  Function to check if two strings are rotations of each other
    *   s1, s2: are the input strings
    */
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.length()!=s2.length())
          return false;
         
        return((s1+s1).find(s2)!=string::npos);  
    }
};

TC:O(N)  AS:O(N)
