class Solution {
public:
    vector<int> cache;
    vector<int> _nums;
    int rob(vector<int>& nums) {
        cache.assign(nums.size(),-1);
        _nums = nums;
        
        return func(nums.size()-1);
    }
    
    int func(int house){
        
        if(house==1)
            return max(_nums[1],_nums[0]);
        if(house==0)
            return _nums[0];
        
        if(cache[house]!=-1)
            return cache[house];
        
        cache[house] = max(func(house-1), func(house-2)+_nums[house]);
        
        return cache[house];
        
    }
};