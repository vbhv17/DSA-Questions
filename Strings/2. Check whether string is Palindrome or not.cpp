class Solution {
	public:
		int isPalindrome(string S)
		{
			int left = 0 , right = s.length() - 1;
			while (left < right)
			{
				if (S[left] != S[right])
					return 0;
				left += 1;
				right -= 1;
			}
			return 1;
		}
	};
  
  TC: O(N)  AS:O(1)   //where N is the length of the string
