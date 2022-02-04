class Solution {
public:
    vector<vector<int>> output;
    vector<int> nums;
    int k;
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        
        for(k=0; k<=nums.size(); k++){
            vector<int> tmp(0);
            backtrack(0,tmp);
        }
        return output;
    }
    
    
    void backtrack(int cur, vector<int>& subset){
        
        if(subset.size()==k){
            output.push_back(subset);
            return;
        }
        
        for(int i=cur; i<nums.size(); i++){
            subset.push_back(nums[i]);
            backtrack(i+1, subset);
            subset.pop_back();
        }
        
        return;
    }
    
};