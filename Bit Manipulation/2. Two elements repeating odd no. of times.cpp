Naive Approach: Traverse each element and count its appearance. If count of any element becomes odd, print that element
TC:O(n*n)  AS:(1)

Efficient Solution:  //Refer Notes & Track
class Solution
{
public:
    void oddAppNos(vector<int> nums)
    {
        int XOR = 0, res1 = 0, res2 = 0;
        for (int i = 0 ; i < nums.size(); i++)  //XOR of all elements
            XOR = XOR ^ nums[i];

        int rsb = XOR & ~(XOR - 1);             //rightmost set bit

        for (int i = 0 ; i < nums.size(); i++)
        { 
            if ((nums[i]&rsb) != 0)            //XOR of elements that have rsb set
                res1 = res1 ^ nums[i];

            else
                res2 = res2 ^ nums[i];        //XOR of elements that have rsb not set

        }
        cout << res1 << " " << res2;
    }
};

TC:O(N)  AS:O(1)
