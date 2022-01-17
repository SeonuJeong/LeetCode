/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* result=NULL;
    ListNode* middleNode(ListNode* head) {
        Func(head,0);
        
        return result;
    }
    
    int Func(ListNode* node, int pos){
        
        if(node == NULL)
            return 0;
        
        int tmp = Func(node->next,pos+1);
        
        if(result!=NULL)
            return 0;
        
        if(pos-1<tmp+1) {result = node; return 0;}
        
        return tmp+1;
        
    }
};