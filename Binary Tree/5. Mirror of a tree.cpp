https://practice.geeksforgeeks.org/problems/mirror-tree/1#

https://www.youtube.com/watch?v=lLdyqkdFNi0&ab_channel=CodeLibrary

class Solution{
    public:
    //Function to convert a binary tree into its mirror tree.
    void mirror(Node* node)
    {
        if(node==NULL)            //Base case
            return;
            
        mirror(node->left);
        mirror(node->right);
        swap(node->left,node->right);
        
    }
};
