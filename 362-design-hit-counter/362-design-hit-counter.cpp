class HitCounter {
public:
    //04:00
    
    vector<int> ts;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        ts.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        
        int lower = upper_bound(ts.begin(),ts.end(),timestamp-300<0?0:timestamp-300)-ts.begin();
        int higher = upper_bound(ts.begin(),ts.end(),timestamp)-ts.begin();
        
        return higher-lower;
        
    }
    
    
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */