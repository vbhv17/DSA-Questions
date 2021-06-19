https://www.youtube.com/watch?v=jWf5F_shzho&t=314s&ab_channel=CodeLibraryCodeLibrary

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

public:

  void dfs(Node *node, Node *clone, vector<Node *> &vis)
  {
    vis[clone->val] = clone;

    for (auto x : node->neighbors)
    {
      if (vis[x->val] == NULL)
      {
        Node *newNode = new Node(x->val);
        clone->neighbors.push_back(newNode);
        dfs(x, newNode, vis);
      }

      else
      {
        clone->neighbors.push_back(vis[x->val]);
      }
    }
  }
  
  Node* cloneGraph(Node* node) {

    if (node == NULL) return NULL;

    vector<Node *> vis(1000, NULL);
    Node *clone = new Node(node->val);
    dfs(node, clone, vis);
    return clone;

  }
};

TC: O(V+E)
SC: O(V)
