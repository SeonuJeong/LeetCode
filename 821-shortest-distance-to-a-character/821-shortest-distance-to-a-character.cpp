class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int le=-1,ri=0;
        int cur=0;
        vector<int> result(s.length(),0);
        
        while(ri<=s.length()){
            
            if(s[ri]==c || ri == s.length()){
                cur = le+1;
                while(cur!=ri){
                    result[cur] = min(le!=-1?cur-le:INT_MAX, ri!=s.length()?ri-cur:INT_MAX);
                    cur++;
                }
                
                le = ri;
            }
            ri++;
        }
        
        return result;
        
    }
};