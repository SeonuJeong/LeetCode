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
    
    unordered_map<int,int> posthash;
    unordered_map<int,int> inhash;
    vector<int> inorder;
    vector<int> postorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        
        TreeNode* root;
        
        for(int i=0; i<inorder.size(); i++)
            inhash[inorder[i]] = i;
        
        for(int i=0; i<postorder.size(); i++)
            posthash[postorder[i]] = i;
        
        return makeTree(0,inorder.size()-1,inhash[postorder[postorder.size()-1]],root);
        
    }
    // le, ri in inorder
    // key in inorder
    // first key is postorder[postorder.size()-1]
    // key is root in postorder
    // postorder[root] -> root and postorder[root-1] -> right and postorder[root-rightsubtreeSize] -> left
    
    
    TreeNode* makeTree(int le, int ri, int key, TreeNode* root){
        
        if(le>ri) return NULL;
        
        root = new TreeNode(inorder[key]);
        
        
        int keyInPost = posthash[inorder[key]];
        
        if(keyInPost-1>=0){
            int next = keyInPost-1;
            root->right = makeTree(key+1,ri,inhash[postorder[next]],root->right);
        }
        
        if(keyInPost-(ri-key+1)>=0){
            int next = keyInPost-(ri-key+1);
            root->left = makeTree(le,key-1,inhash[postorder[next]],root->left);
        }
        
        return root;
        
    }
};