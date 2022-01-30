class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> pmap;
        map<char,int> smap;
        vector<int> result;
        if(s.length()<p.length())
            return result;
        
        for(int i=0; i<p.length(); i++){
            map<char,int>::iterator it = pmap.find(p[i]);
            if(it != pmap.end())
                it->second++;
            else
                pmap.insert(pair<char,int>(p[i],1));
        }
    
        int i=0,j=0;
        
        while(j<s.length()){
            map<char,int>::iterator it = smap.find(s[j]);
            if(it != smap.end())
                it->second++;
            else
                smap.insert(pair<char,int>(s[j],1));
            
            if(j>=p.length()-1){
                if(pmap==smap) result.push_back(i);
                
                map<char,int>::iterator left = smap.find(s[i]);
                if(left!=smap.end()) left->second--;
                
                if(left!=smap.end() && left->second==0)
                    smap.erase(left);
                
                i++;
            }
            j++;
        }
        
        return result;
        
    }
};