// Solution 1: 
// => Pass a range for every node
// => For root, range is -inf to inf
// => For left child of a root in range, we change upperbound as the nodes value -1
// => For right child of root in range, we change lowerbound as the nodes value +1
  
bool isBSTUtil(Node * root, int min, int max)
{
        if(root==NULL)
            return true;
            
        if(root->data<min || root->data>max)
            return false;
            
        return (isBSTUtil(root->left, min, root->data-1) 
                &&
                isBSTUtil(root->right, root->data+1, max)
                );
}
 bool isBST(Node* root) 
 {
      return isBSTUtil(root, INT_MIN, INT_MAX);
 }

TC: O(n)
SC: O(n) ~ O(h) Average case



// Solution 2: 
// Using inorder traversal
// A Binary tree is a BST if it its inorder traversal is sorted

// Solve without extra space for array to store inorder traversal items

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    int prev = INT_MIN;
    
    bool isBST(Node * root)
    {
        if(root==NULL)
            return true;
            
        if(isBST(root->left)==false)
            return false;
        
        if(root->data<=prev)
            return false;
            
        prev = root->data;
        
        return (isBST(root->right));
    }
};

TC: O(n)
SC: O(h)
