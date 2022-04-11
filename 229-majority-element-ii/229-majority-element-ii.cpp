class Solution {
public:
    //0855
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        
        for(int i=0; i<nums.size(); i++){
            um[nums[i]] += 1;
        }
        
        int more = nums.size()/3;
        vector<int> result;
        for(unordered_map<int,int>::iterator it=um.begin(); it!=um.end(); it++){
            if(it->second > more)
                result.push_back(it->first);
        }
        
        return result;
    }
};