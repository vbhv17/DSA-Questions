https://www.youtube.com/watch?v=3MmWkR04n_8&ab_channel=CodeLibrary

Solution:
Node* LCA(Node *root, int n1, int n2)
{
  if (!root) return NULL;

  if (root->data == n1 or root->data == n2)
    return root;

  Node *left = LCA(root->left, n1, n2);
  Node *right = LCA(root->right, n1, n2);

  if (left and right)
    return root;

  if (left)
    return left;
  else
    return right;
}

TC: O(N) ~ where n is the number of nodes in BST ~ Since we are travesing each node 
SC :O(H) ~ We will be havin max nodes=height of tree in rec call stack
