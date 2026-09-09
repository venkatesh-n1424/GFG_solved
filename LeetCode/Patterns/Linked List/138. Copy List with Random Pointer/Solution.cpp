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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mpp;
        if(head==NULL) return NULL;
        Node* new_head = new Node(head->val);
        Node* cur=new_head;
        Node* t=head;
        mpp[t]=cur;
        while(t->next!=NULL){
            t=t->next;
            Node* copy = new Node(t->val);
            cur->next=copy;
            cur=cur->next;
            mpp[t]=cur;
        }
        cur->next=NULL;
        cur=new_head;
        t=head;
        while(cur!=NULL){
            if(t->random==NULL) {
                cur->random=NULL;
                cur=cur->next;
                t=t->next;
            }
            else{
                cur->random=mpp[t->random];
                cur=cur->next;
                t=t->next;
            }
        }
        return new_head;
    }
};