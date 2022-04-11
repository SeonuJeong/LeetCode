class Solution {
public:
    //0855
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int more = nums.size()/3;
        
        int count=0;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(i!=0 && nums[i]!=nums[i-1])
                count=1;
            else
                count++;
            
            if(count<=more)
                continue;
            
            result.push_back(nums[i]);
            
            while(i+1<nums.size()&&nums[i+1]==nums[i])
                i++;
        }
        
        return result;
    }
};