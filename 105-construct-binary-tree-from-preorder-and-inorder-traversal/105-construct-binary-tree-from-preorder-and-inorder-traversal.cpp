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
    
    unordered_map<int,int> inhash;
    unordered_map<int,int> prehash;
    vector<int> inorder;
    vector<int> preorder;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        
        for(int i=0; i<preorder.size(); i++){
            prehash[preorder[i]] = i;
        }
        
        for(int i=0; i<inorder.size(); i++){
            inhash[inorder[i]] = i;
        }
        
        TreeNode* root;
        return makeTree(0,inorder.size()-1,inhash[preorder[0]],root); 
    }
    
    TreeNode* makeTree(int le, int ri, int key, TreeNode* root){
        
        if(le>ri) return NULL;
        
        root = new TreeNode(inorder[key]);
        
        int pre = prehash[inorder[key]];
        int nextkey;
        if(pre+1 < preorder.size()){
            nextkey = inhash[preorder[pre+1]];
            root->left = makeTree(le,key-1,nextkey,root->left);
        }
        
        int dif = key-le+1;
        if(pre+dif<preorder.size()){
            nextkey = inhash[preorder[pre+dif]];
            root->right = makeTree(key+1,ri,nextkey,root->right);
        }
        return root;
    }
};