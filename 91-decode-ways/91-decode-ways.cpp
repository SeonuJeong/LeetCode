class Solution {
public:
    string s;
    int numDecodings(string s) {
        this->s =s;
        
        if(s[0]=='0') return 0;
        if(s.length()==1) return 1;
        
        vector<int> dp(s.length(),0);
        dp[0]=1;
        
        for(int i=1; i<s.length(); i++){
            
            if(s[i]!='0'){
                dp[i] += dp[i-1];
            }
            
            bool flag = checkTwo(i);
            if(flag){
                if(i!=1)
                    dp[i] += dp[i-2];
                else
                    dp[i] += 1;
            }
            else if(!flag && s[i]=='0'){
                return 0;
            }
        }
        
        
        return dp[s.length()-1];
        
    }
    
    bool checkTwo(int cur){
        
        if(s[cur-1]=='0') return false;
        
        int tmp = stoi(s.substr(cur-1,2));
        
        if(tmp>=10 && tmp<=26){
            return true;
        }
        
        return false;
    }
};