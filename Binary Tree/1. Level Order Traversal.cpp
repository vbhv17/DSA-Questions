
Efficient Solution (Using Queue):
// For each node, first the node is visited and printed and then if its left and right child exists then they are pushed into the queue
// We stop the loop when queue becomes empty.

vector<int> levelOrder(Node* node)
{
  queue<Node *> q;
  q.push(node);
  vector<int> ans;
  while (!q.empty())
  {
    Node *curr = q.front();

    ans.push_back(q.front()->data);

    if (curr->left)
      q.push(curr->left);

    if (curr->right)
      q.push(curr->right);

    q.pop();
  }
  return ans;
}

TC: O(N)  SC:O(N)
