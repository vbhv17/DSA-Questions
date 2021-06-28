https://www.youtube.com/watch?v=5P84A0YCo_Y&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=11&t=25s&ab_channel=AdityaVerma
https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
public:
    int kthGrammar(int n, int k) {
         
        if(n==1 && k==1)
            return 0;
        
        int mid = pow(2,n-1)/2;
        
        if(k<=mid)
            return kthGrammar(n-1,k);
        
        else
            return !kthGrammar(n-1,k-mid);
        
        return 0;
        
    }
};

