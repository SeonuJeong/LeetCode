class Solution {
public:
    
    unordered_map<int,vector<string>> um;
    
    vector<vector<string>> output;
    string s;
    vector<vector<string>> partition(string s) {
        this->s = s;
        vector<string> result;
        dfs(0,result);
        return output;
    }
    
    void dfs(int index, vector<string>& result){
        
        if(index == s.length()){
            output.push_back(result);
        }
        
        
        for(int i=index; i<s.length(); i++){
            
            if(!checkPalindrome(index, i)) continue;
            
            result.push_back(s.substr(index,i-index+1));
    
            dfs(i+1,result);
                
            result.pop_back();
        }
        
        return ;
    }
    
    bool checkPalindrome(int le, int ri){
        
        while(le<ri){
            if(s[le]!=s[ri])
                return false;
            le++;
            ri--;
        }
        
        return true;
    }
};