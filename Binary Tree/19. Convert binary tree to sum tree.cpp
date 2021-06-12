Problem: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#
Solution: https://www.youtube.com/watch?v=ait6N1Dihls&ab_channel=KashishMehndiratta
class Solution {
public:

  // Convert a given tree to a tree where every node contains sum of values of
  // nodes in left and right subtrees in the original tree

  int recSumTree(Node *root)
  {
    if (root == NULL)
      return 0;

    int lsum = recSumTree(root->left);
    int rsum = recSumTree(root->right);

    int val = root->data + lsum + rsum;
    root->data = lsum + rsum;

    return val;
  }
  void toSumTree(Node *node)
  {
    recSumTree(node);

  }
};

TC: O(N)
SC: O(H)
