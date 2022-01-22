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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* last = new ListNode();
        ListNode* result = last;
        while(list1!=NULL || list2!=NULL){
            ListNode* tmp1 = list1;
            ListNode* tmp2 = list2;
            
            if(tmp1==NULL){
                last->next=tmp2;
                list2=list2->next;
            }
            else if(tmp2==NULL){
                last->next=tmp1;
                list1=list1->next;
            }
            else{
                if(tmp1->val>tmp2->val){
                    last->next = tmp2;
                    list2=list2->next;
                }
                else{
                    last->next = tmp1;
                    list1=list1->next;
                }
            }
            last = last->next;
        }
        
        return result->next;
    }
};