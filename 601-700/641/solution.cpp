//数组+双指针维护队列
class MyCircularDeque {
public:
    vector<int> container;
    int sz;
    int front, last;

    MyCircularDeque(int k) {
        container = vector<int>(k);
        front = 0;
        last = 0;
        sz = 0;
    }
    
    bool insertFront(int value) {
        if(sz == container.size()) return false;
        --front;
        if(front < 0) front = container.size() - 1;
        container[front] = value;
        ++sz;
        return true;
    }
    
    bool insertLast(int value) {
        if(sz == container.size()) return false;
        container[last] = value;
        ++last;
        ++sz;
        if(last == container.size()) last = 0;
        return true;
    }
    
    bool deleteFront() {
        if(!sz) return false;
        ++front;
        --sz;
        if(front == container.size()) front = 0;
        return true;
    }
    
    bool deleteLast() {
        if(!sz) return false;
        --last;
        --sz;
        if(last < 0) last = container.size() - 1;
        return true;
    }
    
    int getFront() {
        if(!sz) return -1;
        return container[front];
    }
    
    int getRear() {
        if(!sz) return -1;
        if(!last) return container[container.size() - 1];
        return container[last - 1];
    }
    
    bool isEmpty() {
        return !sz;
    }
    
    bool isFull() {
        return sz == container.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
