class Solution {
public:
    //10:07
    vector<int> nums;
    vector<vector<int>> result;
    vector<vector<int>> before;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        dfs(0);
        result.push_back(vector<int>(0));
        return result;
    }
    
    void dfs(int i){
        
        if(i==nums.size()-1){
            result.push_back(vector<int>(1,nums[i]));
            before.push_back(vector<int>(1,nums[i]));
            return;
        }
        
        dfs(i+1);
        
        if(nums[i] != nums[i+1]){
            before.clear();
            int size = result.size();        
            for(int j=0; j<size; j++){
                vector<int> tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
                before.push_back(tmp);
            }
        
            result.push_back(vector<int>(1,nums[i]));
            before.push_back(vector<int>(1,nums[i]));
        }
        else{
            
            int size = before.size();        
            for(int j=0; j<size; j++){
                vector<int> tmp = before[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
                before.push_back(tmp);
            }
            before.erase(before.begin(),before.begin()+size);
        }
        
        return;
    }
};