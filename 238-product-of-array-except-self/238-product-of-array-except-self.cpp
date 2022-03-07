class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int right = 1;
        int left =1;
        
        vector<int> answer(nums.size(),1);
        
        for(int i=nums.size()-1; i>=1; i--){
            //right[i-1] = nums[i]*right[i];
            answer[i-1] = nums[i]*right;
            right = answer[i-1];
        }
        
        for(int i=0; i<nums.size()-1; i++){
            //left[i+1] = left[i] * nums[i];
            left = left*nums[i];
            answer[i+1] = answer[i+1] * left;
        }
        
        
        return answer;
    }
};