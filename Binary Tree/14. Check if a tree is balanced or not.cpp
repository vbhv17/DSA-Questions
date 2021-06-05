Naive: For every node, calculate height of its left subtree, height of its right subtree, take the absolute difference.
       If the difference is < 1 then recursively call for left subtree and right subtree
int height(Node *root)
{
    if(root==NULL)
      return 0;
      
    return 1 + max(height(root->left),height(root->right));
}


int checkBalance(Node *root)
{
    if(root==NULL)
      return 1;
      
    int lh = height(root->left);
    int rh = height(root->right);
    
    return (abs(lh-rh)<=1 && checkBalance(root->left) && checkBalance(root->right));
}
bool isBalanced(Node *root)
{
    return (checkBalance(root));
    
}


Efficient:
int f = 1;
int checkBalance(Node *root)
{
  if (root == NULL)
    return 0;

  int lh = checkBalance(root->left);            //left and right heights are calculated while checking for balance
  int rh = checkBalance(root->right);

  if (abs(lh - rh) > 1) {
    f = 0;
    return f;
  }

  return max(lh, rh) + 1;
}
bool isBalanced(Node *root)
{
  f = 1;
  checkBalance(root);
  return (f);
}

TC: O(N)
