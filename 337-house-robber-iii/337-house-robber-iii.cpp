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
    //08:45
    
    unordered_map<TreeNode*,int> cache;
    int rob(TreeNode* root) {
        
        return dp(root);
        
    }
    
    int dp(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }
        
        if(cache[root]!=0) return cache[root];
        
        int skip=root->val;
        int child=0;
        
        if(root->left!=NULL){
            skip += dp(root->left->left);
            skip += dp(root->left->right);
            child += dp(root->left);
        }
        
        if(root->right!=NULL){
            skip += dp(root->right->left);
            skip += dp(root->right->right);
            child += dp(root->right);
        }
        
        cache[root] = max(skip,child);
        return cache[root];
    }
    
    int CalSize(TreeNode* root){
        
        if(root==NULL) return 0;
        
        return 1+max(CalSize(root->left),CalSize(root->right));
    }
};