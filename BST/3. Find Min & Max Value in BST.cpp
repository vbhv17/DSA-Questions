Recursive Code To Find MIN
int minValue(Node* root)
{
    if(root==NULL)
        return -1;
        
    Node *curr=root;
    if(curr->left==NULL)
        return curr->data;
    
    else
        return minValue(curr->left);
}

TC:O(h)  AS:O(h)
  

  Iterative Code to find MIN
  int minValue(Node* root)
{
    if(root==NULL)
        return -1;
        
    Node *curr=root;
    
    while(curr->left!=NULL)
        curr=curr->left;
    
    return curr->data;   
}

TC:O(h)  AS:O(1)
  
  
  Recursive Code To Find MAX
  int minValue(Node* root)
{
    if(root==NULL)
        return -1;
        
    Node *curr=root;
    if(curr->right==NULL)
        return curr->data;
    
    else
        return minValue(curr->right);
}
TC:O(h)  AS:O(h)

  Iterative Code to find MAX
  int minValue(Node* root)
{
    if(root==NULL)
        return -1;
        
    Node *curr=root;
    
    while(curr->right!=NULL)
        curr=curr->right;
    
    return curr->data;   
}

TC:O(h)  AS:O(1)
  
