class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> um;
    
    TimeMap() {
            
    }
    
    void set(string key, string value, int timestamp) {

        if(um.find(key)==um.end()){
            um[key] = vector<pair<string,int>>(0);
            um[key].push_back(make_pair(value, timestamp));
        }
        else{
            um[key].push_back(make_pair(value, timestamp));
        }
    }
    
    string get(string key, int timestamp) {
        
        for(int i=um[key].size()-1 ; i>=0 ; i--){
            if(um[key][i].second <= timestamp){
                return um[key][i].first;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */