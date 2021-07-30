Bruteforce:
Check all possible substring starting from each character
If we encounter a substring which includes all characters of given string, update the answer
#include<bits/stdc++.h>
using namespace std;
int main() {

   string str;
   cin >> str;
   int n = str.length();

   //using a set to count the distinct characters in the string
   set<char> st;
   for (int i = 0; i < n; i++)
      st.insert(str[i]);

   //k distinct characters 
   int k = st.size();

   unordered_map<char, int> mp;

   int ans = INT_MAX;
   int i, j, count;

   for (i = 0; i < n; i++) {
      //including first character in substring
      count = 1;
      mp[str[i]] = 1;

      for (j = i + 1; j < n; j++) {
        
         //including more characters in our substring and incrementing frequency in map
         mp[str[j]]++;
         //if frequency is 1 now that means it was 0 previously which means we have a new character in substring 
         if (mp[str[j]] == 1) {
            //and therefore we increase count
            count++;
         }
 
         //if count of chars in substring becomes equal to number of distinct chars
         //that means we have found a valid substring which includes all distinct characters of string
         if (count == k) {
            //updating the ans
            ans = min(ans, j - i + 1);
            //setting frequency count of all characters back to zero
            //since from the next iteration we will check for new substring
            for (auto it = mp.begin(); it != mp.end(); it++)
               it->second = 0;
            break;
         }
      }
   }
   cout << ans;
}


TC: O(N*N)
SC: O(N)
  
  
Efficient Solution:
Using sliding window technique
#include<bits/stdc++.h>
using namespace std;
int main() {

   string str;
   cin >> str;
   int n = str.length();
   
   //using a set to count the distinct characters in the string
   set<char> st;
   for (int i = 0; i < n; i++)
      st.insert(str[i]);

   string res = "";
   //k distinct characters
   int k = st.size();

   unordered_map<char, int> mp;

   int ans = INT_MAX;
   int i = 0, j = i + 1, count = 1;
   mp[str[i]]++;

   while (i <= j && j < n) {
      
      //we dont have all chars in current window so expand the window by adding 
      //more chars from right side
      if (count < k) {
         // if we are encountering a new character in our window
         if (mp[str[j]] == 0)
            count++;
         mp[str[j]]++;
         j++;  //expand window
      }

      //we have got all the characters in the current window so shrink the 
      //window from left side and check if count is still == k 
      //then we can get a smaller window
      else if (count == k) {
         ans = min(ans, j - i);
         res = str.substr(i,j);
         // if we are removing a character which was occuring only once in our window
         if (mp[str[i]] == 1)
            count--;
         mp[str[i]]--;
         i++;  //shrink window
      }
   }

   while (count == k) {
      ans = min(ans, j - i);
      res = str.substr(i,j);
      if (mp[str[i]] == 1)
         count--;
      mp[str[i]]--;
      i++;
   }

   cout << ans;
}

TC: O(N)
SC: O(1)

























