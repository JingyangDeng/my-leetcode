//数组存放数据，使用双指针维护循环队列
class MyCircularQueue {
public:
    int l, r, sz;
    vector<int> container;
    MyCircularQueue(int k) {
        container = vector<int>(k);
        l = 0; r = 0; sz = 0;
    }
    
    bool enQueue(int value) {
        if(sz < container.size()){
            container[r] = value;
            ++r; ++sz;
            if(r == container.size()) r = 0;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(sz > 0){
            ++l; --sz;
            if(l == container.size()) l = 0;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(!sz) return -1;
        return container[l];
    }
    
    int Rear() {
        if(!sz) return -1;
        if(!r) return container[container.size()-1];
        return container[r-1];
    }
    
    bool isEmpty() {
        return !sz;
    }
    
    bool isFull() {
        return sz == container.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
