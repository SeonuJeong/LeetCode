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
    //02:56
    vector<vector<int>> result;
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        while(root->val!=INT_MIN){
            result.push_back(vector<int>(0));
            dfs(root);
        }
        
        return result;
    }
    
    int dfs(TreeNode* root){
    
        if(root==NULL){
            return -1;    
        }
        
        if(root->left==NULL && root->right==NULL){
            result.back().push_back(root->val);
            root->val = INT_MIN;
            return -1;
        }

        if(dfs(root->left)==-1){
            root->left = NULL;
        }
        
        if(dfs(root->right)==-1){
            root->right = NULL;
        }
        
        return 1;
    }
};