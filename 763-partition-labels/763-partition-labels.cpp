class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> rm(26,-1);
       
        for(int i=s.length()-1; i>=0; i--){
            if(rm[s[i]-'a'] == -1) rm[s[i]-'a'] = i;
        }
        
        vector<int> result;
        int l=0, j=0;
        
        for(int i=0; i<s.length();i++){
            
            j = max(j,rm[s[i]-'a']);
            
            if(i==j){
                result.push_back(j-l+1);
                l = i+1;
            }
            
        }
        return result;
    }
};