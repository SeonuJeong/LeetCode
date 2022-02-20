class Solution {
public:
    //02:20
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> um;
        
        for(string s : words)
            um[s]++;
        
        unordered_map<string,int>::iterator it = um.begin();
        vector<pair<int,string>> v;
        for( ; it!=um.end(); it++){
            v.push_back(make_pair(it->second, it->first));
        }
        
        sort(v.begin(), v.end(), cmp);
        
        vector<string> result;
        for(int i=0; i<k; i++){
            result.push_back(v[i].second);
        }
        
        return result;
        
    }
    
    static bool cmp(pair<int,string> a, pair<int,string> b){
        
        if(a.first==b.first){
            if(a.second<b.second) return true;
            else return false;
        }
        
        if(a.first>b.first)
            return true;
        else
            return false;
        
    }
};