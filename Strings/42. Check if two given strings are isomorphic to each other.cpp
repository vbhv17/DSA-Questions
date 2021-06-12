https://www.geeksforgeeks.org/check-if-two-given-strings-are-isomorphic-to-each-other/
https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

Approach 1:
1. Count the occurence of every character in both the strings
In this approach, we will count the number of occurrences of a particular character in both the string using two arrays, while we will compare the two arrays if at any moment with the loop the count of the current character in both strings becomes different we return false, else after the loop ends we return true.
Follow the code given below you will understand everything.
  
  class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    { 
        int count1[256]={0};
        int count2[256]={0};
        
        if(str1.length()!=str2.length())
           return false;
      
        for(int i=0;i<str1.length();i++)
        {
            count1[str1[i]]++;
            count2[str2[i]]++;
            
            if(count1[str1[i]]!=count2[str2[i]])
                return false;
        }  
        return true;
    }
};


Approach 2:
The idea is to create an array to store mappings of processed characters. 
  
  1) If lengths of str1 and str2 are not same, return false.
2) Do following for every character in str1 and str2
   a) If this character is seen first time in str1, 
      then current of str2 must have not appeared before.
      (i) If current character of str2 is seen, return false.
          Mark current character of str2 as visited.
      (ii) Store mapping of current characters.
   b) Else check if previous occurrence of str1[i] mapped
      to same character.
     
     
 class Solution
{
public:
  //Function to check if two strings are isomorphic.
  bool areIsomorphic(string str1, string str2)
  {
    if (str1.length() != str2.length())
      return false;

    int m1[256] = {0};
    int m2[256] = {0};

    for (int i = 0; i < str1.length(); i++)
    {
      if (!m1[str1[i]] && !m2[str2[i]]) { //if they are not mapped, then map them
        m1[str1[i]] = str2[i];
        m2[str2[i]] = str1[i];
      }

      else if (m1[str1[i]] != str2[i])   //if m1[str1[i]] was not mapped yet or mapped with a different char
        return false;
    }

    return true;
  }
};

TC: O(|len of any string|)  //since both string length are equal
SC: O(Number of different characters)

