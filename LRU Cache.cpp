class LRUCache {
public:

    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> cache_map;
    int capacity;
    int size = 0; 

    LRUCache(int cap) : capacity{cap} { }

    void moveFront(list<pair<int,int>>::iterator it){
        int key = it->first;  
        int val = it->second;

        cache.erase(it);
        cache.push_front({key, val});
    }

    int get(int key) {

        if(cache_map.count(key)){
            moveFront(cache_map[key]); 
            cache_map[key] = cache.begin();
            return cache_map[key]->second;
        }
        else 
            return -1;
    }
    
    void put(int key, int val) {

        if(get(key) == -1){
            if(size < capacity){
                cache.push_front({key, val});
                cache_map[key] = cache.begin();
                size++;  
            } else {
                int keyDeleted = cache.back().first;
                cache.pop_back();
                cache_map.erase(keyDeleted);

                cache.push_front({key, val});
                cache_map[key] = cache.begin(); 
            }
        } else
            cache.begin()->second = val;
    }

};