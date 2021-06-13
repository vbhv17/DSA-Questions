https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/

Naive: Inorder traversal of BST is sorted in increasing order, so we find the inorder of BST
       and store it in a vector and then return vector[k-1]th element which would be the 
       kth smallest elemnent
 
void recInorder(Node *root, vector<int> &inorder)
{
    if(!root) return; 
    recInorder(root->left, inorder);
    inorder.push_back(root->data);
    recInorder(root->right, inorder);
}

class Solution {
public:

  void solve(TreeNode* root, vector<int>& inorder)
  {
    if (!root) return;
    solve(root->left, inorder);
    inorder.push_back(root->val);
    solve(root->right, inorder);
  }

  int kthSmallest(TreeNode* root, int k) {
    vector<int> inorder;

    solve(root, inorder);

    return (inorder[k - 1]);

  }
};

TC: O(N) SC:O(N)
  
  
Efficient Solution: https://www.youtube.com/watch?v=KqMm81Y7j9M
We do inorder traversal, but rather than storing elements in a vector we keep track of elements
encountered so far, if we have processed k elements that means we are at our target element kth smallest element.
                      
class Solution {
public:
    int solve(TreeNode* root, int &k)
    {
        if(!root) return 0; 
        
        int left = solve(root->left, k);   //left
        //if left subtree returned a non zero value we have found the kth smallest element
        if(left)                           
            return left;
        
        k-=1;                             //root
        if(k==0)
            return root->val;
        
        int right = solve(root->right, k);   //right
        //whether right subtree returned a zero or a non zero value, we return it
        return right;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
       return solve(root, k);
      
    }
};
    
TC: O(N)
Auxillary Space : O(N) ~ In case of a skewed tree ~ O(H) in general

                                                                                                                 
