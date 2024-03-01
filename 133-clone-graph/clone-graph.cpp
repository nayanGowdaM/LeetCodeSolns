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
    Node* vis[102];
    Node* solve(Node* node ){
        if(!node) return NULL;
        Node* root= new Node(node->val);
        vis[node->val] = root;
        for(auto it : node->neighbors){
            if(vis[it->val] == NULL)
            root->neighbors.push_back(solve(it));
            else root->neighbors.push_back(vis[it->val]);
        }
        return root;
    }
public:
    Node* cloneGraph(Node* node) {
        memset(vis, NULL, sizeof(vis));
        return solve(node);
    }
};