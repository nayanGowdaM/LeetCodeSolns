/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*>cur, next;
        cur.push(root);
        while(!cur.empty()){
            Node* node = cur.front();
            cur.pop();
            if(node->left) next.push(node->left);
            if(node->right) next.push(node->right);
            if(cur.empty()){
                node->next=NULL;
                swap(cur, next);
            }
            else {
                node->next=cur.front();
            }
        }
        return root;
        
    }
};