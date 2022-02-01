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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            
            TreeNode* tmp = que.front();
            que.pop();
            
            if(tmp->val == subRoot->val){
                if(dfs(tmp,subRoot)) return true;
            }
            
            if(tmp->left!=NULL) que.push(tmp->left);
            if(tmp->right!=NULL) que.push(tmp->right);
        }
        
        return false;
    }
    
    bool dfs(TreeNode* root, TreeNode* subRoot){
        
        if(root==NULL && subRoot==NULL) return true;
        else if(root==NULL || subRoot==NULL) return false;
        
        if(root->val!=subRoot->val) return false;
        
        if(!dfs(root->left,subRoot->left)) return false;
        if(!dfs(root->right,subRoot->right)) return false;
        
        return true;
    }
};