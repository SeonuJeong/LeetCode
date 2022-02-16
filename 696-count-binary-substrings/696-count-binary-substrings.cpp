class Solution {
public:
    //08:30
    //08:53
    int countBinarySubstrings(string s) {
        
        int before=0;
        int cur=1;
        
        if(s.length()==1) return 0;
        
        int count=0;
        for(int i=1; i<s.length(); i++){
            
            if(s[i]!=s[i-1]){
                before = cur;
                cur=1;
            }
            else{
                cur++;
            }
            
            if(before>=cur) count++;
        }
        
        return count;
    }
};