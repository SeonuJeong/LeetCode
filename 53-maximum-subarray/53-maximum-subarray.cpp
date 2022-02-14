class Solution {
public:
    
    vector<int> cache;
    vector<int> nums;
    int maxSubArray(vector<int>& nums) {
        this->nums = nums;
        cache.assign(nums.size(),-1);
        
        int mx = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int tmp =dp(i);
            if(mx<tmp){
                mx=tmp;
            }
        }
        
        return mx;
    }
    
    int dp(int i){
        
        if(i==nums.size()-1){
            return nums[i];
        }
        
        if(cache[i]!=-1){
            return cache[i];
        }
        
        cache[i] = max(nums[i],nums[i]+dp(i+1));
        
        return cache[i];
    }
};