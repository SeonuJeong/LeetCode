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
    ListNode* deleteDuplicates(ListNode* head) {
        
        return func(head,NULL);
    }
    
    ListNode* func(ListNode* cur, ListNode* before){
        
        if(cur==NULL) return NULL;
        
        ListNode * result = func(cur->next, cur);
        
        if(before!=NULL && before->val==cur->val){
            return result;
        }
        else if((before!=NULL&&before->val!=cur->val)||before==NULL){
            if(cur->next != NULL &&cur->val == cur->next->val)
                return result;
            else
                cur->next = result;
        }
        return cur;
        
    }
};