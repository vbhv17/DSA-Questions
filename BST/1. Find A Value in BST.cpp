Search a value in BST : Given root node & a value x, find if x is present in BST or not  //Refer Notes
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
 
 
 Insertion In BST 
 Recursive & Iterative
 
 Recursive:
Node *insert(Node *root, int x)
{

   if(root==NULL)
      return new Node(x);

   else if(root->key<x)
      root->right=insert(root->right,x);

   else if(root->key>x)
      root->left=insert(root->left,x);
   
   return root;

}
TC: O(h)  AS:O(h)

 
 Iterative:
Node *insert(Node *root, int x)
{

   Node *temp = new Node(x);             //creating a new node
   Node *parent = NULL;                  //maintining parent pointer for getting accces to leaf node (previous of curr) to which new node would be attached because curr will become NULL
   Node *curr = root;
   while (curr != NULL)
   {
      parent = curr;                     

      if (cur->key > x)
         curr = curr->left;

      else if (curr->key < x)
         curr = curr->right;

      else
         return root;

   }

   if (parent == NULL)
      return temp;

   if (parent->key > x)
      parent->left = temp;

   else
      parent->right = temp;

   return root;

}
TC: O(h)  AS:O(1)
