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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=0,n2=0;
        ListNode* cur=l1;
        while(cur){
            n1=n1*10+cur->val;
            cur=cur->next;
        }
        cur=l2;
        while(cur){
            n2=n2*10+cur->val;
            cur=cur->next;
        }
        int res1=0,res2=0;
        while(n1){
            res1=res1*10+(n1%10);
            n1/=10;
        }
        while(n2){
            res2=res2*10+(n2%10);
            n2/=10;
        }
        int res=res1+res2;
        ListNode* dnode = new ListNode(0);
        if(res==0) return dnode;
        cur=dnode;
        while(res){
            ListNode* node=new ListNode(res%10);
            res/=10;
            cur->next=node;
            cur=cur->next;
        }
        cur->next=nullptr;
        ListNode* op=dnode->next;
        dnode->next=nullptr;
        return op;
    }
};
