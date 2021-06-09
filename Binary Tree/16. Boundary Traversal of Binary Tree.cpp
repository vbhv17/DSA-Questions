https://www.youtube.com/watch?v=Csk6QEFyrtQ&ab_channel=KashishMehndiratta

Approach: We take all the left boundary nodes first (excluding leaf nodes if any),
          Then we take all the leaf nodes
          Then we take all the right boundary nodes (excluding leaf nodes if any)
            
            
void leftTree(Node *root, vector<int> &ans)
{
    if(!root)
        return;
        
    if(root->left || root->right)
        ans.push_back(root->data);
    
    if(root->left)
        leftTree(root->left, ans);
    
    else if(root->right)
        leftTree(root->right, ans);
        
}

void rightTree(Node *root, vector<int> &ans)
{
    if(!root)
        return;
    
    if(root->right)
        rightTree(root->right, ans);
        
    else if(root->left)
        rightTree(root->left, ans);
    
    if(root->left || root->right)
        ans.push_back(root->data);
        
}
void leaf(Node *root, vector<int> &ans)
{
    if(!root)
        return;
    
    leaf(root->left, ans);
    
    if(!root->left && !root->right)
        ans.push_back(root->data);
        
    leaf(root->right, ans);
    
}

class Solution {
public:
    vector <int> printBoundary(Node *root)
    {
        vector<int> ans;
        if(!root)
            return ans;
        
        ans.push_back(root->data);
        leftTree(root->left, ans);
        leaf(root, ans);
        rightTree(root->right, ans);
        
    }
};

Time Complexity: O(N) ~ Visiting each node exactly once
Auxiliary Space: O(Height of the Tree)
