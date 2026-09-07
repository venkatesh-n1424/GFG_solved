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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int sz=0;
        // ListNode* cur=head;
        // while(cur){
        //     sz++;
        //     cur=cur->next;
        // }
        // if(sz==1){
        //     return nullptr;
        // }
        // int pos=sz-n+1;
        // cur=head;
        // if(pos==1){
        //     head=cur->next;
        //     cur->next=nullptr;
        //     return head;
        // }
        // ListNode* prev=NULL;
        // while(--pos){
        //     prev=cur;
        //     cur=cur->next;
        // }
        // prev->next=cur->next;
        // cur->next=nullptr;
        // return head;
        ListNode* f=head,*s=head;
        for(int i=0;i<n;i++) f=f->next;
        if(!f){
            ListNode* newhead=head->next;
            head->next=nullptr;
            return newhead;
        }
        while(f->next){
            s=s->next;
            f=f->next;
        }
        ListNode* dnode=s->next;
        s->next=dnode->next;
        dnode->next=nullptr;
        return head;
    }
};