class Solution {
public:
    vector<int> nums;
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        dfs(0);
        result.push_back(vector<int>(0));
        return result;
    }
    
    void dfs(int i){
        
        if(i==nums.size()-1){
            result.push_back(vector<int>(1,nums[i]));
            return;
        }
        
        dfs(i+1);
        int size = result.size();        
        for(int j=0; j<size; j++){
            vector<int> tmp = result[j];
            tmp.push_back(nums[i]);
            result.push_back(tmp);
        }
        
        result.push_back(vector<int>(1,nums[i]));
        
        return;
    }
};