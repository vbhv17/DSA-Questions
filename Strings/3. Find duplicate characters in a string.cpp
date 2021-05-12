Using Map
We store count of occurences of all characters in the input string, whichever character has occurence count > 1, we print that character

#include<bits/stdc++.h>
using namespace std;
int main()
{
  
   string s;
   cin>>s;
   map<char, int > count;

   for(int i=0;i<s.length();i++)
       count[s[i]]++;

   for(auto it: count)
   {
      if(it.second>1)
        cout<<(it.first)<<" ";
   }
  return 0;

}

TC: O(NLogN)  why?
SC: O(k) where 0 <= k <= N
