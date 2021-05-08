// Efficient Solution: (Using the idea of level order traversal line by line)
// We have all elements of a particular level in the queue at every iteration,
// we print only the last element of the queue

#TLDR: We do level order traversal and print the last node in every level.

vector<int> rightView(Node *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;

  queue<Node*> q;

  q.push(root);

  while (!q.empty())
  {
    int count = q.size();

    for (int i = 0; i < count; i++)
    {
      Node *curr = q.front();
      q.pop();

      if (i == count - 1)
        ans.push_back(curr->data);

      if (curr->left)
        q.push(curr->left);

      if (curr->right)
        q.push(curr->right);
    }
  }
  return ans;
}

TC: O(N)  
SC:Theta(width) ~ O(N)
