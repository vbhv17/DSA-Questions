Follow Aditya Vermas Recursion steps..
  1. Base Condition
  2. Hypothesis
  3. Induction

class Solution
{
public:

   int checkSumTree(Node *root, bool &flag) {

      //Base Condition
      if (root == NULL)
         return 0;
      if (root->left == NULL && root->right == NULL)
         return root->data;
      if (flag == false)
         return 0;

      //Hypotheses
      int lsum = checkSumTree(root->left, flag);
      int rsum = checkSumTree(root->right, flag);

      //Induction
      if (root->data != lsum + rsum)
         flag = false;

      return root->data + lsum + rsum;

   }

   bool isSumTree(Node* root)
   {
      bool flag = true;
      checkSumTree(root, flag);

      return flag;
   }
};

TC: O(N)
SC: O(H)
