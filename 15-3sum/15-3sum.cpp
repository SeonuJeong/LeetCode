class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        unordered_set<int> dup;
        unordered_map<int,int> seen;
        
        for(int i=0; i<nums.size(); i++){
            
            if(dup.insert(nums[i]).second){
                for(int j=i+1; j<nums.size(); j++){
                    int complement = -nums[i]-nums[j];
                    
                    auto it = seen.find(complement);
                    
                    if(it!=seen.end() && it->second==i){
                        vector<int> tmp = {complement,nums[i],nums[j]};
                        sort(tmp.begin(), tmp.end());
                        res.insert(tmp);
                    }
                    
                    seen[nums[j]]=i;
                }
                
            }
        }
        
        return vector<vector<int>> (res.begin(),res.end());
    }
};