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
        queue<Node*> que;
        
        if(root!=NULL){
            que.push(root);
        }
        else
            return root;
        
        while(!que.empty()){
            
            int count = que.size();
            
            while(count>0){
                
                Node* tmp = que.front();
                que.pop();
                
                if(count!=1){
                    tmp->next = que.front();
                }
                else{
                    tmp->next = NULL;
                }
                
                if(tmp->left!=NULL) que.push(tmp->left);
                if(tmp->right!=NULL) que.push(tmp->right);
                
                count--;
            }
            
        }
        
        return root;
        
    }
};