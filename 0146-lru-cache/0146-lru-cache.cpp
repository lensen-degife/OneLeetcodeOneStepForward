class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll;                          
    unordered_map<int, list<pair<int, int>>::iterator> cache;  

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        auto it = cache[key];
        dll.splice(dll.begin(), dll, it);

        return it->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            auto it = cache[key];
            it->second = value;
            dll.splice(dll.begin(), dll, it);
        } else {
            if (dll.size() == capacity) {
                int lruKey = dll.back().first;
                dll.pop_back();
                cache.erase(lruKey);
            }

            dll.emplace_front(key, value);
            cache[key] = dll.begin();
        }
    }
};