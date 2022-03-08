class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> result;
        set<vector<int>> fsck;
        
        for(int fir=0; fir<n; fir++){

            for(int sec=fir+1; sec<n; sec++){
                
                vector<int> tmp = {nums[fir], nums[sec]};
                if(fsck.find(tmp)!=fsck.end())
                    continue;
                
                reverse(tmp.begin(),tmp.end());
                if(fsck.find(tmp)!=fsck.end())
                    continue;
                
                fsck.insert(tmp);
                
                set<vector<int>> lrck;
                
                int curTarget = target - (nums[fir]+nums[sec]);
                
                int le=sec+1,ri=n-1;
                
                while(le<ri){
                    if(nums[le]+nums[ri] > curTarget)
                        ri--;
                    else if(nums[le]+nums[ri]<curTarget)
                        le++;
                    else{
                        vector<int> ans={nums[fir], nums[sec], nums[le], nums[ri]};
                        vector<int> lrv = {nums[le], nums[ri]};
                        
                        if(lrck.find(lrv)==lrck.end()){
                            reverse(lrv.begin(), lrv.end());
                            if(lrck.find(lrv)==lrck.end()){
                                result.push_back(ans); 
                                lrck.insert(lrv);
                            }
                        }
                        
                        le++;
                    }
                }
            }
        }
        return result;
        
    }
};