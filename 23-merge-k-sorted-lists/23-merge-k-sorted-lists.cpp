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
    //12:02
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> p(lists.size());
        
        for(int i=0; i<lists.size(); i++){
            p[i] = lists[i];
        }
        
        ListNode* result=NULL;
        ListNode* back=NULL;
        while(true){
            
            int minIndex = FindMinVal(p);
            
            if(minIndex==-1) break;
            else{
                if(result==NULL){
                    result = p[minIndex];
                    back = result;
                }
                else{
                    back->next = p[minIndex];
                    back = back->next;
                }
                
                p[minIndex] = p[minIndex]->next;
            }
        }
        
        return result;
    }
    
    int FindMinVal(vector<ListNode*>& p){ // return min val's p index
        
        int mn = INT_MAX;
        int index=-1;
        
        for(int i=0; i<p.size(); i++){
            
            if(p[i]!=NULL && p[i]->val<mn){
                index=i;
                mn = p[i]->val;
            }
            
        }
        
        if(index==-1)
            return -1;
        else
            return index;
    }
};