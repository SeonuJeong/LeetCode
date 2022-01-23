class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        return func(nums);
    }
    
    vector<vector<int>> func(vector<int>& unused){
        
        vector<vector<int>> result;
        
        if(unused.empty()){
            vector<vector<int>> v;
            return v;
        }
        else{

            for(int i=0; i<unused.size(); i++){
                int tmp = unused.front();
                unused.erase(unused.begin());
                vector<vector<int>> v = func(unused);
                
                if(v.size()!=0){
                    for(int i=0; i<v.size(); i++){
                        v[i].insert(v[i].begin(), tmp);
                        result.push_back(v[i]);
                    }
                    
                    
                }
                else{
                    v.push_back(vector<int>(1,tmp));
                    result.push_back(v[0]);
                }
                    
                unused.push_back(tmp);
            }
        }
        
        return result;
    }
    
};