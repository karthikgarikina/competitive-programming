class MyHashMap {
public:
    int MAXLEN = 1000001;
    vector<int> Map;
    MyHashMap() {
        Map.assign(MAXLEN, -1);
    }
    
    void put(int key, int value) {
        Map[key] = value;
    }
    
    int get(int key) {
        return Map[key];
    }
    
    void remove(int key) {
        Map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */