Node *getSuccessor(Node *curr)  //to get closest greater value of the node we want to delete
{
   curr = curr->right;
   while (curr != NULL && curr->left != NULL)
      curr = curr->left;

   return curr;
}


Node *deleteNode(Node *root,  int X)
{
   if (root == NULL)
      return root;
   if (root->data > X)
      root->left = deleteNode(root->left, X);
   else if (root->data < X)
      root->right = deleteNode(root->right, X);
   else                                            //when we reach the node to be deleted
   {
      if (root->left == NULL)                      //when left child is empty, also handles the case when both childs are empty 
      {
         Node *temp = root->right;
         delete root;
         return temp;

      }

      else if (root->right == NULL)               //when right child is empty
      {
         Node *temp = root->left;
         delete root;
         return temp;
      }

      else                                       //when both childs are non empty, we find the inorder succesor & replace it with the node which we are deleting
      {
         Node *succ = getSuccessor(root);
         root->data = succ->data;
         root->right = deleteNode(root->right, succ->data);
      }
      return root;
   }

}

TC:O(h)    AS:O(h)
