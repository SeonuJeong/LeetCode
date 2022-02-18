/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        dfs(head);
    }
    
    
    void dfs(ImmutableListNode* root){
        if(root==NULL){
            return;
        }
        
        dfs(root->getNext());
        root->printValue();
    }
};