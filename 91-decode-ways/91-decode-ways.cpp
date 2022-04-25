class Solution {
public://1030
    //dp
    
    vector<int> cache;
    string s;
    int numDecodings(string s) {
        cache.assign(s.length(),-1);
        this->s = s;
        return dp(0);
    }
    
    int dp(int pos){
        
        if(pos==s.length())
            return 1;
        
        if(s[pos]=='0')
            return 0;
        
        if(cache[pos]!=-1)
            return cache[pos];
        
        int result=0;
        
        result += dp(pos+1);
        
        if(pos+1==s.length()){
            cache[pos]=result;
            return result;
        }
        string tmp = s.substr(pos,2);
        int convert = stoi(tmp);
        
        if(convert>=1 && convert<=26)
            result += dp(pos+2);
        
        
        cache[pos] = result;
        return result;
    }
    
};