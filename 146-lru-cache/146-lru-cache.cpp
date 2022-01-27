class LRUCache {
public:
    int capacity;
    vector<int> cache;
    queue<int> LRU;
    vector<int> cnt;
    int cursize=0;
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.assign(10001,-1);
        cnt.assign(10001,0);
    }
    
    int get(int key) {
        
        if(cache[key]==-1) return -1;
        
        LRU.push(key);
        cnt[key]++;
        return cache[key];
        
    }
    
    void put(int key, int value) {
        //있으면 넣고 LRU 최신화
        if(cache[key]!=-1){
            cache[key] = value;
            LRU.push(key);
            cnt[key]++;
        }
        else if(cursize<capacity){ // cache에 공간 남으면 NOT evict
            cache[key] = value;
            LRU.push(key);
            cnt[key]++;
            cursize++;
        }
        else{ // pop해야할 때
            int k;
            while(!LRU.empty()){
                k = LRU.front(); LRU.pop();
                cnt[k]--;
                if(cnt[k]==0) break;
            }
            
            cache[k] = -1;
            cache[key] = value;
            LRU.push(key);
            cnt[key]++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */