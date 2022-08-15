//简单模拟
class OrderedStream {
    vector<string> container;
    int ptr;
    
public:
    OrderedStream(int n) {
        container = vector<string>(n+1);
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ret;
        container[idKey] = value;
        while(ptr < container.size() && container[ptr].size()){
            ret.emplace_back(container[ptr]);
            ++ptr;
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
