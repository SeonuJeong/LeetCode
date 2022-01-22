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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> que;
        que.push(root);
        int count=que.size();
        
        while(!que.empty()){
            
            
            while(count){
                TreeNode * tmp = que.front();
                que.pop();
                
                if(tmp == u){
                    if(count==1) return NULL;
                    else    return que.front();
                }
                
                if(tmp->left!=NULL) que.push(tmp->left);
                if(tmp->right!=NULL) que.push(tmp->right);
                count--;
            } // while(count)
            count = que.size();
        }// while(!que.empty())
        
        return NULL;
    }
};