class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        if(head == nullptr)return nullptr;
        while(curr != nullptr){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = curr->next->next;
        }
        Node* dummy = new Node(-1);

        dummy->next = head->next;
        Node* res = dummy->next;
        Node* temp = head;

        //assigned the random ptrs
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next; 
        }

        //handle the next ptrs
        Node* newHead = dummy;
        curr = head;

        while (curr) {
            newHead->next = curr->next; 
            curr->next = curr->next->next; 
            curr = curr->next; 
            newHead = newHead->next; 
        }
        res = dummy->next;
        return res;
    }
};
