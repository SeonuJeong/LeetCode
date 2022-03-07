class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right(nums.size(),1);
        vector<int> left(nums.size(),1);
        
        for(int i=nums.size()-1; i>=1; i--){
            right[i-1] = nums[i]*right[i];
        }
        
        for(int i=0; i<nums.size()-1; i++){
            left[i+1] = left[i] * nums[i];
        }
        
        vector<int> answer(nums.size());
        for(int i=0; i<nums.size(); i++){
            answer[i] = right[i] * left[i];
        }
        
        return answer;
    }
};