Efficient Solution: We use the idea of "print level order traversal line by line"
  
//   Size of the queue (Number of nodes in the queue ) will tell us the number of nodes present in a particular level of the tree
//   If we are traversing the first element of that level then we push it in answer vector
//   We push left and right nodes (if they exist) of every node in each iteration

 
vector<int> leftView(Node *root)
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

      if (i == 0)
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
