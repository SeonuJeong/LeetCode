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
    // Solution1
    int back=0;
    ListNode* front=NULL;
    ListNode* before=NULL;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        Func(head,n);
        
        if(before==NULL){
            return front;
        }
        
        before->next = front;
        
            
        return head;
        
    }
    
    ListNode* Func(ListNode* node, int n){
        if(node==NULL){
            return NULL;
        }

        ListNode* tmp = Func(node->next,n);
        back++;
        
        if(n==back){
            front = node->next;
            return node;
        }
        
        if(tmp!=NULL&&n+1==back){
            before = node;
        }
        
        return NULL;
            
    }
};