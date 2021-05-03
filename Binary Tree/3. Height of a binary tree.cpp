Recursive Solution:

int height(struct Node* node){
        
        if(node==NULL)
         return 0;
         
        return max(height(node->left), height(node->right)) + 1;
    }

TC: O(N)  SC:O(N)
