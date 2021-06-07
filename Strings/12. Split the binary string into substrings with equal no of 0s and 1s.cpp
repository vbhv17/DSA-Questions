#include<bits/stdc++.h>
using namespace std;
#define ll long long
int maxSubStr(string str, int n)
{
    // To store the count of 0s and 1s
    int count0 = 0, count1 = 0;
 
    // To store the count of maximum
    // substrings str can be divided into
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            count0++;
        }
        else {
            count1++;
        }
        if (count0 == count1) {
            ans++;
        }
    }
  
    // It is not possible to
    // split the string
    if (ans == 0) {
        return -1;
    }
    return ans;
}

int main()
{
  int n;
  cin >> n; 
  string s;
  cin >> s;
  cout << maxSubStr(s, n);
}

TC: O(N)  SC:O(1)
