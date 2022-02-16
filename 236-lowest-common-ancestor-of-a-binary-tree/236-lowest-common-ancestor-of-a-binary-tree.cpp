/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //01:42
    TreeNode* result;
    TreeNode* p;
    TreeNode* q;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p; 
        this->q = q;
        
        dfs(root);
        return result;
    }
    
    int dfs(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }
        
        int count=0;
        if(root->val==p->val || root->val==q->val)
            count++;
        
        count += dfs(root->left) + dfs(root->right);
        
        if(count==2){
            result = root;
            count = 0;
        }
        
        return count;
        
    }
};