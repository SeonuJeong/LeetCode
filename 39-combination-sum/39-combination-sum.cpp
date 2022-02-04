class Solution {
public:
    //08:25
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> output(0);
        
        if(target<0){
            return vector<vector<int>>(0);
        }
        
        if(target==0){
            return vector<vector<int>>(1,vector<int>(0));
        }
        
        for(int i=0; i<candidates.size(); i++){
            vector<vector<int>> tmp;
            int dele=candidates[i];
            
            tmp = combinationSum(candidates, target-dele);
           
            if(tmp.size()!=0){
                for(vector<int> cur : tmp){
                    cur.push_back(dele);
                    sort(cur.begin(),cur.end());
                    
                    bool flag = true;
                    
                    for(vector<int> out:output){
                        if(out==cur){ flag =false; break;}
                    }
                    
                    if(flag)
                        output.push_back(cur);
                }
            }
        }
        
        return output;
    }
};