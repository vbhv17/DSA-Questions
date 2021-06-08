https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1#
https://www.youtube.com/watch?v=LhXPvhrhcIk

vector<int> diagonal(Node *root)
{
  vector<int> ans;
  if (!root) return ans;

  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *node = q.front();
    q.pop();
    while (node)
    {
      if (node->left)
        q.push(node->left);

      ans.push_back(node->data);

      node = node->right;
    }
  }

  return ans;
}

TC:O(N)
SC:O(N)
