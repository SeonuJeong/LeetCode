class Solution {
public:
    //05:03
    
    unordered_map<string,int> m;
    string s;
    vector<int> cache; 
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        for(string str : wordDict){
            m.insert(make_pair(str,0));
        }
        
        cache.assign(s.length(),-1);
        
        return backTrack(s.length()-1);
    }
    
    int backTrack(int index){
        
        if(index<0)
            return 1;
        
        if(cache[index]!=-1){
            return cache[index];
        }
        
        for(int i=index; i>=0; i--){
            
            string tmp = s.substr(i,index-i+1);
            
            unordered_map<string,int>::iterator it = m.find(tmp);
            
            if(it!=m.end()){
                 if(backTrack(i-1)){
                     cache[index]=1;
                     return 1;
                 }  
            }
        }
        
        cache[index] = 0;
        return 0;
        
    }
    
};