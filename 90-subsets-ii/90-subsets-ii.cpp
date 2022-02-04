class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> output;
        
        output.push_back(vector<int>(0));
        output.push_back(vector<int>(1,nums[0]));
        
        vector<vector<int>> before;
        before.push_back(vector<int>(1,nums[0]));
        
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                vector<vector<int>> tmp;
                
                for(vector<int> cur : before){
                    cur.push_back(nums[i]);
                    output.push_back(cur);
                    tmp.push_back(cur);
                }
                
                before.clear();
                for(vector<int> cur : tmp){
                    before.push_back(cur);
                }
            
            }
            else{
                before.clear();
                vector<vector<int>> subset;
                for(vector<int> cur : output){
                    cur.push_back(nums[i]);
                    subset.push_back(cur);
                    before.push_back(cur);
                }
            
                for(vector<int> cur : subset){
                    output.push_back(cur);
                }
            }
        }
        
        
        return output;
    }
};