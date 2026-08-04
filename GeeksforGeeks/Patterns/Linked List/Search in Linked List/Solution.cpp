/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        Node* cur=head;
        while(cur){
            if(cur->data==key) return true;
            cur=cur->next;
        }
        return false;
    }
};
