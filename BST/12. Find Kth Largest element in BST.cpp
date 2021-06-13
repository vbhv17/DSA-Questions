https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#
//Same as kth smallest, we're just traversing the tree from the right side first

class Solution
{
    public:
    
    int solve(Node *root, int &K)
    {
        if(!root)
            return 0;
            
        int right = solve(root->right, K);
        
        if(right)
            return right;
        
        K-=1;
        if(K==0)
          return root->data;
        
        int left= solve(root->left, K);
        return left;
    }
    
    int kthLargest(Node *root, int K)
    {
        return solve(root,K);
    }
};

TC:O(N)
SC:O(N) ~ For a skewed tree, O(H) in genral
