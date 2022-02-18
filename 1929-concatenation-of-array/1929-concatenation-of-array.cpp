class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size()*2);
        
        int N = nums.size();
        for(int i=0; i<ans.size(); i++){
            ans[i] = nums[i%N];
        }
        
        return ans;
    }
};