class Solution {
public:
    //1000
    int lengthOfLongestSubstring(string s) {
        

        unordered_map<char,int> seen;
        int maxlen=0;
        int le=0;
        
        for(int ri=0; ri<s.length();ri++){
            
            if(seen.find(s[ri])==seen.end()||seen[s[ri]]==-1){
                seen[s[ri]]=ri;
                maxlen = max(maxlen,ri-le+1);
                continue;
            }
            
            int target = seen[s[ri]];
            
            while(le<=target){
                seen[s[le++]]=-1;
            }
            seen[s[ri]]=ri;
        }
        
        
        return maxlen;
    }
};