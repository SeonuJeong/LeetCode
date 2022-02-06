class Solution {
public:
    //03:44
    bool canJump(vector<int>& nums) {
        int last=nums.size()-1;
        int index=last-1;
        
        if(last==0)return true;
        
        while(index>=0){
            
            if(nums[index]>= last-index){ // can reach last index
                last = index;
                index = index-1;
            }
            else{ // can't reach last index
                index = index-1;
            }
            
        }
        
        if(last==0) return true;
        else return false;
        
    }
};