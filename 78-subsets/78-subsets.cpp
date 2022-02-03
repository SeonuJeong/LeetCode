class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output(1,vector<int>(0));
        
        for(int num : nums){
            vector<vector<int>> newSubsets;
            
            for(vector<int> curr : output){
                curr.push_back(num);
                newSubsets.push_back(curr);
            }
            
            for(vector<int> curr : newSubsets){
                output.push_back(curr);    
            }
     
        }
        
        return output;
    }
    
};