vector<int> topView(Node *root)
    {
        vector<int>  ans;
        if(root==NULL)
            return ans;
            
        queue<pair<Node *, int>> q;
        map<int,int> mp;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto p = q.front();
            Node *curr = p.first;
            int hd = p.second;
            
            if(mp.count(hd) == 0)
                mp[hd] = curr->data;
                
            if(curr->left!=NULL)
                q.push({curr->left, hd-1});
                
            if(curr->right!=NULL)
                q.push({curr->right, hd+1});
                
            q.pop();
            
        }
        
        for(auto x : mp)
            ans.push_back(x.second);
            
        return ans;
        
    }

TC: O(N)
SC: O(N)
