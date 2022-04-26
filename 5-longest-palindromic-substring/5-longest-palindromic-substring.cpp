class Solution {
public:
    
    int longest;
    string result="";
    string s;
    vector<vector<int>> cache;
    string longestPalindrome(string s) {
        this->s = s;
        cache.assign(s.length(),vector<int>(s.length(),-1));
        
        palindrome(0,s.length()-1);
        
        return result;
    }
    
    int palindrome(int le,int ri){
        
        if(le>ri){
            return 1;
        }
        else if(le==ri){
            if(longest==0){
                longest=1;
                result = s[le];
            }
            return 1; 
        }
        
        if(cache[le][ri]!=-1)
            return cache[le][ri];
        
        if(palindrome(le+1,ri-1)&&s[le]==s[ri]){
            if(longest<(ri-le+1)){
                longest = ri-le+1;
                result = s.substr(le,ri-le+1);
            } 
            
            cache[le][ri]=1;
            return 1;
        }
        
        palindrome(le+1,ri)||palindrome(le,ri-1);
        cache[le][ri]=0;
        return 0;
    }
    
};