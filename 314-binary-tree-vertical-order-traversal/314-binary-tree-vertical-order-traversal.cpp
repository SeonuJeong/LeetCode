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
    int leftLen=0;
    int rightLen=0;
    
    vector<vector<int>> result; 
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        if(root==NULL)
            return result;

        dfs(root,0);
        
        leftLen = abs(leftLen);
        result.assign(leftLen+rightLen+1,vector<int>(0));
        
        queue<pair<TreeNode*,int>> que;
        que.push(make_pair(root,0));
        
        while(!que.empty()){
            pair<TreeNode*,int> out = que.front(); que.pop();
            int col = out.second;
            TreeNode* head = out.first;
            
            result[col+leftLen].push_back(head->val);
            
            if(head->left != NULL)
                que.push(make_pair(head->left,col-1));
            
            if(head->right != NULL)
                que.push(make_pair(head->right,col+1));
            
        }
        
        return result;

    }
    
    void dfs(TreeNode* head,int col){
        
        if(head==NULL) return;
        
        leftLen = min(leftLen,col);
        rightLen = max(rightLen,col);
        
        dfs(head->left,col-1);
        dfs(head->right,col+1);
        
    }
    
};