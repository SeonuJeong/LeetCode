/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    priority_queue< int, vector<int>, greater<int> > pq;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    
        queue<TreeNode*> que;
        
        // root1
        if(root1!=NULL)
            que.push(root1);
        
        while(!que.empty()){
            
            TreeNode* tmp = que.front();
            que.pop();
            pq.push(tmp->val);
            
            if(tmp->left!=NULL) que.push(tmp->left);
            if(tmp->right!=NULL) que.push(tmp->right);                
            
        }
        
        //root2
        if(root2!=NULL)
            que.push(root2);
        
        while(!que.empty()){
            
            TreeNode* tmp = que.front();
            que.pop();
            pq.push(tmp->val);
            
            if(tmp->left!=NULL) que.push(tmp->left);
            if(tmp->right!=NULL) que.push(tmp->right);                
            
        }
        
        // pop the priority_queue and store in vector<int>
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
    }

};