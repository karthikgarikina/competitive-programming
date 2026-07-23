class MyHashSet {
public:
    int MAXLEN = 1000001;
    vector<bool>Map;
    MyHashSet() {
        Map.assign(MAXLEN, 0);
    }
    
    void add(int key) {
        Map[key] = 1;
    }
    
    void remove(int key) {
        Map[key] = 0;
    }
    
    bool contains(int key) {
        return Map[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */