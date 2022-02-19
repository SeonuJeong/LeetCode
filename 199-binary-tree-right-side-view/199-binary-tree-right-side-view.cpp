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
    //03:27
    vector<int> result;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,1);
        return result;
    }
    
    void dfs(TreeNode* root, int height){
        
        if(root==NULL){
            return ;
        }
        
        if(result.size()<height){
            result.push_back(root->val);
        }
        
        dfs(root->right, height+1);    
        dfs(root->left, height+1);
        
        return ;
    }
    
};