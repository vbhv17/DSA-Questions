Search a value in BST : Given root node & a value x, find if x is present in BST or not
2 Methods: Iterative & Recursive

 Recursive:
 bool search( Node *root, int x )
{

   if (root == NULL)
      return false;

   else if (root->key == x)
      return true;

   else if (root->key > x)
      return (root->left, x);

   else
      return (root->right, x);
}

TC: O(h)  AS:O(h)

Iterative Method:

bool search( Node *root, int x )
{
   while (root != NULL)
   {
      if (root->key == x)
         return true;

      else if (root->key > x)
         root = root->left;

      else
         root = root->right;
   }

   return false;
}

TC: O(h)  AS:O(1)
