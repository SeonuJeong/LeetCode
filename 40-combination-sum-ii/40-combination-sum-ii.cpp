class Solution {
public:
    //10:30
    
    int target;
    vector<int> candidates;
    vector<vector<int>> result;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        this->target = target;
        backTrack(0,0,vector<int>(0));
        
        return result;
    }
    
    void backTrack(int start, int remain, vector<int> collection){
        
        if(remain>target) return; 
        
        if(remain==target){
            result.push_back(collection);        
        }
        
        for(int i=start; i<candidates.size(); i++){
            
            if(i!=0 && start!=i && candidates[i-1]==candidates[i]) continue;
            
            collection.push_back(candidates[i]);
            backTrack(i+1,remain+candidates[i],collection);
            collection.pop_back();
        }
        
        return;
    }
};