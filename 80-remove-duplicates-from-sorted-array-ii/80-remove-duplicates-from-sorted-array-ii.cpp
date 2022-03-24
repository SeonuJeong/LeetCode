class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sameCount=0;
        int curNum=nums[0];
        int jump=0;
        int k=0;
        for(int i=0; i+jump<nums.size(); i++){
            
            if(curNum!=nums[i+jump]){ 
                curNum=nums[i+jump];
                sameCount=1;
            }
            else
                sameCount++;
            
            if(sameCount<=2){
                if(i+jump>=nums.size())
                    break;
                swap(nums[i],nums[i+jump]);
                k++;
                continue;
            }
            
            while(i+jump<nums.size()&&nums[i+jump]==curNum){
                jump++;
            }
            
            if(i+jump>=nums.size()) break;
            
            curNum = nums[i+jump];
            sameCount=1;
            swap(nums[i],nums[i+jump]);
            k++;
        }
        
        return k;
    }
};