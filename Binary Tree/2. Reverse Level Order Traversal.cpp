Efficient Solution (Using Queue):
// Same as level order traversal, only difference is that we push right child first in the queue before left child and in the end we reverse the order of ans to get reverse level order traversal
// For each node, first the node is visited and printed and then if its right and left child exists then they are pushed into the queue
// In the end we reverse the ans
// We stop the loop when queue becomes empty.


vector<int> reverseLevelOrder(Node *root)
{
  vector<int> ans;

  if (root == NULL)
    return ans;

  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *curr = q.front();

    ans.push_back(q.front()->data);

    if (curr->right)
      q.push(curr->right);

    if (curr->left)
      q.push(curr->left);

    q.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

TC:O(N)  SC:O(N)
