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
            if(j==s.length()-1){
                result.push_back(j-l+1);
                break;
            }
            
            if(i==j){
                result.push_back(j-l+1);
                l = i+1;
                j = rm.find(s[l])->second;
            }
            
            map<char,int>::iterator fd = rm.find(s[i]);
            
            if(fd->second>j)
                j = fd->second;
            
            
        }
        return result;
    }
};