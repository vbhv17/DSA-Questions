Naive: Find inorder traversal of the BST and store it in an array.
       Then compare key and return predecessor(element on left of key)
       and successor (element on right of key) in array.
  TC: O(N)
  SC: O(N)
  
Efficient Solution:

https://www.youtube.com/watch?v=lQIXz5NJYLs&ab_channel=CodeLibrary

Node *inpre(Node *root) {
    Node *curr = root->left;
    while (curr->right)
        curr = curr->right;

    return curr;
}

Node *insuc(Node *root) {
    Node *curr = root->right;
    while (curr->left)
        curr = curr->left;

    return curr;
}


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (!root)  return;

    if (key == root->key) {
        if (root->left)
            pre = inpre(root);

        if (root->right)
            suc = insuc(root);
    }

    else if (key > root->key) {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }

    else if (key < root->key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}

TC: O(H)
