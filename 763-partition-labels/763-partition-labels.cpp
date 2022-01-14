class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> rm;
       
        for(int i=s.length()-1; i>=0; i--){
            if(rm.find(s[i]) == rm.end()) rm.insert(pair<char,int>(s[i],i));
        }
        
        vector<int> result;
        int l=0, j=rm.find(s[0])->second;
        
        for(int i=0; i<s.length();i++){
            
            j = max(j,rm.find(s[i])->second);
            
            if(i==j){
                result.push_back(j-l+1);
                l = i+1;
            }
            
            map<char,int>::iterator fd = rm.find(s[i]);
            
        }
        return result;
    }
};