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
        queue<pair<Node*,int>> que;
        que.push(pair<Node*,int>(root,0));
        
        if(root==NULL)
            return root;
        
        while(!que.empty()){
            pair<Node*,int> tmp = que.front();
            que.pop();
            
            if(que.empty())
                tmp.first->next = NULL;
            else if(que.front().second == tmp.second){
                tmp.first->next = que.front().first;}
            else if(que.front().second != tmp.second){
                tmp.first->next = NULL;}
            
            if(tmp.first->left != NULL) que.push(pair<Node*,int>(tmp.first->left,tmp.second+1));
            if(tmp.first->right != NULL) que.push(pair<Node*,int>(tmp.first->right,tmp.second+1));
        }
        
        return root;
    }
};