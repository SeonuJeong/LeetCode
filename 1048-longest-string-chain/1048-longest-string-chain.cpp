class Solution {
public:
    unordered_map<string,int> um;
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        
        int longest=0;
        for(string s:words){
            longest = max(longest,func(s));
        }
        
        return longest;
    }
    
    static bool cmp(string a, string b){
        return a.length()<b.length();
    }
    
    int func(string s){
        
        int len=1;
        
        for(int i=0; i<s.length(); i++){
            string tmp=s;
            len = max(um[s.erase(i,1)]+1,len);
            s=tmp;
        }
        um[s] = len;
        return len;
    }
    
};