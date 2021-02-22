Approach 1: Copy the string in an auxillary string in reverse order and then print the auxillary string
TC: O(N)  AS: O(N)   //where N is length of string

Approach 2: Two Pointer
class Solution {
	public:
		void reverseString(vector<char>& s) {
			int left = 0;
			int right = s.size() - 1;
			while (left < right)
			{
				swap(s[left++], s[right--]);
			}
		}
	};
  
  TC: O(N)  AS: O(1)
