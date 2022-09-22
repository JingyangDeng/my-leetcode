//单链表的实现
class LinkedNode {
public:
    int val;
    LinkedNode* next;
    LinkedNode(int val_):val(val_),next(NULL) {}
    LinkedNode(int val_, LinkedNode* next_):val(val_),next(next_) {}
};

class MyLinkedList {
    LinkedNode* head;
    int length;
public:
    MyLinkedList() {
        head = NULL; length = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= length) return -1;
        LinkedNode* curr = head;
        for(int i = 0; i < index; ++i) curr = curr->next;
        return curr->val;
    }
    
    void addAtHead(int val) {
        head = new LinkedNode(val, head);
        ++length;
    }
    
    void addAtTail(int val) {
        if(!length) head = new LinkedNode(val);
        else {
            LinkedNode* curr = head;
            while(curr->next) curr = curr->next;
            curr->next = new LinkedNode(val);
        }
        ++length;
    }
    
    void addAtIndex(int index, int val) {
        if(index > length) return;
        if(index == length) addAtTail(val);
        else if(index <= 0) addAtHead(val);
        else {
            LinkedNode* curr = head;
            for(int i = 0; i < index - 1; ++i) curr = curr->next;
            curr->next = new LinkedNode(val, curr->next);
            ++length;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= length) return;
        if(!index) {
            LinkedNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            LinkedNode* curr = head;
            for(int i = 0; i < index - 1; ++i) curr = curr->next;
            LinkedNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        --length;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
