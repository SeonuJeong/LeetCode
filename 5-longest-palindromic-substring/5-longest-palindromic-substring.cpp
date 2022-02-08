class Solution {
public:
    // 05:01
    // 06:16
    vector<vector<int>> cache;
    string s;
    string output="";
    int longlen=0;
    string longestPalindrome(string s) {
        cache.assign(s.length(), vector<int>(s.length(),0));
        this->s = s;
        
        for(int i=0; i<s.length(); i++){
            dp(0,i);
        }
        
        return output;
    }
    
    int dp(int left, int right){
        
        
        if(left > right){
            return 1;
        }
        
        if(left==right){
            if(output.length() < 1)
                output = s.substr(left,1);
            
            return 1;
        }
        
        if(cache[left][right]!=0){
            return cache[left][right];
        }
        
        int result=-1;
        for(int i=left; i<right-longlen; i++){
            if(s[i]==s[right]){
                if(dp2(i+1, right-1)>0){
                    result= right-i+1;
                    if(output.length() < s.substr(i,right-i+1).length())
                        output = s.substr(i,right-i+1);
                    break;
                }
            }
        }
        
        cache[left][right] = result;
        return result;
    }
    
    
    int dp2(int left,int right){
        
        if(left==right) return 1;
        if(left>right) return 1;
        
        if(s[left]==s[right]){
            return dp2(left+1,right-1);
        }
        else{
            return -1;
        }
    }
};