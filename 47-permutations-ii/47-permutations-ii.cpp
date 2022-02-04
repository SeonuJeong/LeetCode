class Solution {
public:
    //06:58
    

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,bool> um;
        vector<vector<int>> output;
        
        if(nums.size()==0){
            return vector<vector<int>>(1,vector<int>(0));
        }
        
        for(int i=0; i<nums.size(); i++){
            if(um.find(nums[i])==um.end()){
                um.insert(make_pair(nums[i],true));
            }
            else{
                continue;
            }
            int num = nums[i];
            
            nums.erase(nums.begin()+i);
            vector<vector<int>> tmp = permuteUnique(nums);
            nums.insert(nums.begin()+i,num);
            
            for(vector<int> cur : tmp){
                cur.push_back(num);
                output.push_back(cur);
            }
            
        }
        
        return output;
    }
    
    
};