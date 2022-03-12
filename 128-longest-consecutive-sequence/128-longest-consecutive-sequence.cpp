class Solution {
public:
    //05:43
    
    vector<bool> visited;
    unordered_map<int,int> um;
    vector<int> nums;
    int longestConsecutive(vector<int>& nums) {
        visited.assign(nums.size(),false);
        this->nums = nums;
        
        for(int i=0; i<nums.size(); i++){
            if(um.find(nums[i])!=um.end()){
                visited[i]=true;
            }
            else{
                um[nums[i]]=i;
            }
        }
        
        int maxLen=0;
        for(int i=0; i<nums.size(); i++){
            
            if(visited[i]) continue;
            
            int len=1;
            if(um.find(nums[i]+1)!=um.end())
                len += dfs(i,1);
            
            if(um.find(nums[i]-1)!=um.end())
                len += dfs(i,-1);
            
            maxLen = max(maxLen,len);
        }
        
        return maxLen;
    }
    
    
    int dfs(int index, int dir){
        
        visited[index] = true;
        
        int len=1;
        if(um.find(nums[index]+dir)!=um.end())
            len += dfs(um[nums[index]+dir],dir);
        else
            return 0;
        
        return len;
        
    }
    
    
};