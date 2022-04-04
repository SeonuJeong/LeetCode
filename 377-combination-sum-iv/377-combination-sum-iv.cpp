class Solution {
public:
    
    vector<int> cache;
    vector<int> nums;
    int combinationSum4(vector<int>& nums, int target) {
        this->nums = nums;
        cache.assign(target+1,-1);
        
        sort(nums.begin(), nums.end());
        return combination(target);
    }
    
    int combination(int curTotal){
        
        if(curTotal==0){
            return 1;
        }
        
        if(curTotal<0)
            return 0;
        
        if(cache[curTotal]!=-1)
            return cache[curTotal];
        
        int result=0;
        for(int i=0; i<nums.size(); i++)
            result += combination(curTotal-nums[i]);
        
        cache[curTotal] = result;
        return result;
    }
};