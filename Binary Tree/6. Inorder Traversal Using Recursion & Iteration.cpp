https://leetcode.com/problems/binary-tree-inorder-traversal/

Recursive Solution:
class Solution {
public:
  void recursiveInorder(TreeNode *root, vector<int> &ans)
  {
    if (root == NULL)
      return;

    recursiveInorder(root->left, ans);
    ans.push_back(root->val);
    recursiveInorder(root->right, ans);
    
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    recursiveInorder(root, ans);
    return ans;
  }
};


Iterative Solution:  https://www.youtube.com/watch?v=5y_j0OqD7v8&ab_channel=TECHDOSE

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {

    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = root;

    while (curr != NULL || !s.empty())
    {
      while (curr != NULL)
      {
        s.push(curr);
        curr = curr->left;
      }

      curr = s.top();
      s.pop();
      ans.push_back(curr->val);
      curr = curr->right;
    }
    return ans;
  }
};
