/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //11:14
    Node* copyRandomList(Node* head) {
        
        vector<Node*> v;
        unordered_map<Node*,int> um;
        
        if(head==NULL) return NULL;
        
        Node* before = new Node(-1);
        Node* tmp = head;
        int i=0;
        while(true){
            if(tmp!=NULL){
                before->next = new Node(tmp->val);
                before = before->next;
                v.push_back(before);
                um[tmp] = i++;
            }
            else{
                before->next = NULL;
                break;
            }
            tmp = tmp->next;
        }
        
        tmp = head;
        Node* newHead = v[0];
        
        while(tmp!=NULL){
            
            if(tmp->random!=NULL)
                newHead->random = v[um[tmp->random]];
            else
                newHead->random = NULL;
                
                newHead = newHead->next;
                tmp = tmp->next;
        }
        
        //return은 before->next;
        return v[0];
    }
};