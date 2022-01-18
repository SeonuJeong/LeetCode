class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int le=0, ri=0;
        int mx=0;
        while(ri<s.length()){
            map<char,int>::iterator it = m.find(s[ri]);
            if(it!=m.end()){ // m안에 s[ri]이 있다면
                if(it->second>=le && it->second<=ri)
                    le = it->second+1;
                
                it->second = ri;
                mx = max(mx, ri-le+1);
                ri++;
            }
            else{
                m.insert(pair<char,int>(s[ri],ri));
                mx = max(mx, ri-le+1);
                ri++;
            }
        }
        
        return mx;
    }
};