class Solution {
public:
    //0710
    
    vector<int> nums;
    vector<vector<int>> result;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return result;
        
        sort(nums.begin(),nums.end());
        this->nums = nums;
        
        
        for(int i=0; i<nums.size()-2 ; i++){
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            twoSum(i,-1*nums[i]);
        }
        
        return result;
    }
    
    
    void twoSum(int pos, int target){
        
        int le=pos+1;
        int ri=nums.size()-1;
        
        
        while(le<ri){
            int sum= nums[le]+nums[ri];
            if(sum==target){
                vector<int> output;
                output={nums[pos],nums[le],nums[ri]};
                result.push_back(output);
                
                le++;
                while(le<ri){
                    if(nums[le]!=nums[le-1])
                        break;
                    else
                        le++;
                }
            }
            else if(sum<target){
                le++;
            }
            else{
                ri--;
            }
        }
    }
    
};