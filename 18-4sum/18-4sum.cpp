class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> result;
        
        
        for(int fir=0; fir<n; fir++){
            if(fir!=0 && nums[fir-1]==nums[fir])
                continue;
            for(int sec=fir+1; sec<n; sec++){
                if(sec!=fir+1 && nums[sec-1]==nums[sec])
                    continue;
                
                int curTarget = target - (nums[fir]+nums[sec]);
                
                int le=sec+1,ri=n-1;
                
                while(le<ri){
                    if(nums[le]+nums[ri] > curTarget)
                        ri--;
                    else if(nums[le]+nums[ri]<curTarget)
                        le++;
                    else{
                        vector<int> ans={nums[fir], nums[sec], nums[le], nums[ri]};
                      
                        result.push_back(ans); 

                        while(le<ri){
                            le++;
                            if(nums[le-1]!=nums[le])break;
                        }
                    }
                }
            }
        }
        return result;
        
    }
};