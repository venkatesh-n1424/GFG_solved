/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        // Code here
        Node* cur=head;
        Node* prev=NULL;
        while(cur){
            if(key<=cur->data) break;
            prev=cur;
            cur=cur->next;
        }
        if(cur==head){
            Node* new_node=new Node(key);
            new_node->next=cur;
            head=new_node;
        }
        else if(cur==NULL){
            Node* new_node=new Node(key);
            prev->next=new_node;
        }
        else{
            Node* new_node=new Node(key);
            new_node->next=cur;
            prev->next=new_node;
        }
        return head;
    }
};