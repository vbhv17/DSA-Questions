Recursive Solution:
class Solution {
public:

  void recursivePreorder(TreeNode *root, vector<int> &ans)
  {
    if (root == NULL)
      return;
    recursivePreorder(root->left, ans);
    recursivePreorder(root->right, ans);
    ans.push_back(root->val);

  }

  vector<int> postorderTraversal(TreeNode* root) {

    vector<int> ans;
    recursivePreorder(root, ans);
    return ans;
  }
};


Iterative Solution: https://www.youtube.com/watch?v=k21VKEM8OFY   (Using 2 Stacks)
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {

    vector<int> ans;
    if (root == NULL)
      return ans;

    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    s1.push(root);

    while (!s1.empty())
    {
      TreeNode *curr = s1.top();
      s1.pop();
      s2.push(curr);
      if (curr->left)
        s1.push(curr->left);
      if (curr->right)
        s1.push(curr->right);

    }

    while (!s2.empty())
    {
      TreeNode *item = s2.top();
      s2.pop();
      ans.push_back(item->val);
    }

    return ans;
  }
};
