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
    vector<int> nums;
    
    bool findTarget(TreeNode* root, int k) {
        preorder(root);
        
        for(int i=0; i<nums.size(); i++){
            if(search(root,k-nums[i])&&(nums[i]!=k-nums[i]))
                return true;
        }
        
        return false;
    }
    
    void preorder(TreeNode* root){
        
        if(root==NULL)
            return;
            
        preorder(root->left);
        nums.push_back(root->val);
        preorder(root->right);

    }
    
    int search(TreeNode* root,int k){
        if(root==NULL)
            return 0;
        
        if(root->val == k)
            return 1;
        
        if(k > root->val)
            return search(root->right,k);
        else
            return search(root->left,k);
    }
};