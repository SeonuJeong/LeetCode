class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted;
        unordered_map<string,int> um;
        vector<vector<string>> result;
        
        for(string str : strs){
            sort(str.begin(), str.end());
            sorted.push_back(str);
        }
        
        for(int i=0; i<strs.size(); i++){
            if(um.find(sorted[i])!=um.end()){
                int index = um[sorted[i]];
                result[index].push_back(strs[i]);
                continue;
            }
            
            int index = result.size();
            result.push_back(vector<string>(0));
            result[index].push_back(strs[i]);
            
            um[sorted[i]]=index;
        }
        
        return result;
    }
};