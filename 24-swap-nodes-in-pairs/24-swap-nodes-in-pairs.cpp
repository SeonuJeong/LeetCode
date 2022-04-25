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
    ListNode* originalHead;
    ListNode* swapPairs(ListNode* head) {
        originalHead = head;
        
        swap(head,NULL);
        
        return originalHead;
    }
    
    void swap(ListNode* head,ListNode* before){
        
        if(head==NULL)
            return;
        if(head == originalHead){
            if(head->next!=NULL)
                originalHead = head->next;
        }
        
        ListNode* n = head->next;
        
        if(n==NULL) return;
        
        ListNode* nn = head->next->next;
        
        //1
        head->next = nn;
        
        //2
        n->next = head;
        
        //3
        if(before!=NULL)
            before->next = n;
        
        swap(nn,head);
        return;
    }
};