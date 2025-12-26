//https://leetcode.com/problems/design-linked-list/description/


class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next = NULL;
    };
    Node* head = NULL;
    Node* tail = NULL;
    int l = 0;

public:
    MyLinkedList() {}

    int get(int index) {
        if(index < 0 || index >= l) return -1;
        Node* temp = head;
        while(index--){
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* node = new Node();
        node->val = val;
        node->next = head;
        head = node;
        if(l == 0) tail = node;
        l++;
    }

    void addAtTail(int val) {
        Node* node = new Node();
        node->val = val;
        if(tail == NULL){
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        l++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > l) return;

        if(index == 0){
            addAtHead(val);
        }
        else if(index == l){
            addAtTail(val);
        }
        else{
            Node* temp = head;
            Node* prev = head;
            Node* node = new Node();
            node->val = val;

            while(index--){
                prev = temp;
                temp = temp->next;
            }
            prev->next = node;
            node->next = temp;
            l++;
        }
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= l) return;

        if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            l--;
            if(l == 0) tail = NULL;
            return;
        }

        Node* temp = head;
        Node* prev = head;
        while(index--){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if(temp == tail) tail = prev;
        delete temp;
        l--;
    }
};
