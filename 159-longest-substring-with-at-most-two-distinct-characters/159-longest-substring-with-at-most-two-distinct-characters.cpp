class Solution {
public: //0640
    
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        if(s.length()==1)
            return 1;
        
        int le=0;
        vector distinct={0};       
        int result=1;

        
        for(int ri=1; ri<s.length(); ri++){
            
            bool isInclude = false;
            
            for(int i=0; i<distinct.size(); i++)
                if(s[distinct[i]]==s[ri]){
                    isInclude = true;
                    distinct[i] = ri;
                }
            
            if(isInclude){
                result = max(result,ri-le+1);
                continue;
            }
            
            if(distinct.size()==1){
                distinct.push_back(ri);
                result = max(result,ri-le+1);
                continue;
            }
            
            // 없을때
            
            int non_before;
            for(int i=0; i<2; i++)
                if(s[distinct[i]]!=s[ri-1]){
                    non_before = i;
                }
            
            le = distinct[non_before]+1;
            distinct[non_before] = ri;
                
            result = max(result,ri-le+1);
        }
        
        return result;
    }
};