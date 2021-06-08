https://www.youtube.com/watch?v=iSZOcOe_TE4&ab_channel=KashishMehndiratta
//code by vbhv17
Approach: We want to convert a binary tree into a BST, we know that, inorder traversal of a BST has all the nodes in sorted order.
          So, we traverse the given binary tree using any traversal technique (here inorder), and store data of all the nodes in a vector.
          After that we sort the vector and now we insert these elements one by one  in the binary tree using inorder traversal so that it becomes a BST.  
  
class Solution {
public:
  // The given root is the root of the Binary Tree
  // Return the root of the generated BST

  void retrieveData(Node *root, vector<int> &v)
  {
    if (root == NULL)
      return;

    retrieveData(root->left, v);
    v.push_back(root->data);
    retrieveData(root->right, v);

  }

  void fillBST(Node *root, vector<int> &v , int &curr)
  {
    if (root == NULL)
      return;

    fillBST(root->left, v, curr);
    root->data = v[curr++];
    fillBST(root->right, v, curr);
  }

  Node *binaryTreeToBST (Node *root)
  {
    vector<int> v;
    retrieveData(root, v);
    sort(v.begin(), v.end());
    int curr = 0;
    fillBST(root, v, curr);
    return root;

  }
};

TC: O(NLogN)
SC: O(N)
