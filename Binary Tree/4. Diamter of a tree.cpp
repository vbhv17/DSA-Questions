Naive Solution:
The diameter of a tree T is the largest of the following quantities:

the diameter of T’s left subtree.
the diameter of T’s right subtree.
the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)
  
  
  class Solution
{
    public:
    //Function to return the diameter of a Binary Tree.
    int height(Node *root)
    {
        if(root==NULL)
            return 0;
            
        else
            return 1 + max(height(root->left),height(root->right));
    }
    
    
    int diameter(Node* root)
    {
        if(root==NULL)
            return 0;
            
        int d1 = 1 + height(root->left) + height(root->right);
        int d2 = diameter(root->left);
        int d3 = diameter(root->right);
        
        return max(d1 , max(d2,d3));
    }
};

TC: O(N*N)
  
  
Efficient Solution:
This function returns height but sets the res variable to have the diameter

class Solution
{
    public:
    int res=0;
    int diameter(Node* root)
    {
        if(root==NULL)
            return 0;
            
        int lh=diameter(root->left);
        int rh=diameter(root->right);
        
        res=max(res, 1+lh+rh);
        
        return 1+max(lh,rh);
        
    }
};
