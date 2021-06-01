https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

https://www.youtube.com/watch?v=M5U8bBBn970

// Modify level order traversal to print alternate levels in reverse order.

vector <int> zigZagTraversal(Node* root)
{
  vector<int> ans;
  queue<Node *> q;

  if (!root) return ans;   //Base Case

  q.push(root);
  int flag = 1;            //Setting flag at level 1 (odd level, move from left to right)
  while (!q.empty())
  {
    vector<int> temp;
    int sz = q.size();
    while (sz--)
    {
      Node *node = q.front();
      q.pop();

      temp.push_back(node->data);

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }

    if (flag % 2 == 0)
      reverse(temp.begin(), temp.end());    //if it is even level, reverse the temp arr since we need elements in right to left order

    for (int i = 0; i < temp.size(); i++)     //push this level into ans vector (odd level is pushed in the same order, even level is pushed in reverse order)
      ans.push_back(temp[i]);

    flag = !flag;                          //inverting the level
  }
  return ans;
}

TC: O(N)
SC: O(N)
