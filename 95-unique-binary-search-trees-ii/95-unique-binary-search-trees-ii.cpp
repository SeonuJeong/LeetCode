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
    vector<TreeNode*> generateTrees(int n) {
        
        vector<int> v;
        for(int i=1; i<=n; i++)
            v.push_back(i);
        
        return BST(v);
        
    }
    
    vector<TreeNode*> BST(vector<int> v){
        
        if(v.size()==0){
            vector<TreeNode*> tmp(0);
            tmp.push_back(NULL);
            return tmp;
        }
        
        vector<TreeNode*> output;
        for(int i=0; i<v.size(); i++){
            
            vector<int> left(0);
            vector<int> right(0);
            if(i!=0) left = {v.begin(),v.begin()+i};
            if(i!=v.size()-1) right = {v.begin()+i+1,v.end()};
            
            vector<TreeNode*> Lresult = BST(left);
            vector<TreeNode*> Rresult = BST(right);
            
            for(int l=0; l<Lresult.size(); l++){
                for(int r=0; r<Rresult.size(); r++){
                    TreeNode *head = new TreeNode(v[i]);
                    head->left = clone(Lresult[l]);
                    head->right = clone(Rresult[r]);
                    output.push_back(head);
                }
            }
            
        }
        
        return output;
    }
    
    TreeNode* clone(TreeNode* v){
        if(v==NULL) return NULL;
        TreeNode * cn = new TreeNode(v->val);
        cn->left = clone(v->left);
        cn->right = clone(v->right);
        return cn;
    }
};