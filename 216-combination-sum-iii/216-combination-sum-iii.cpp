class Solution {
public:
    //0518
    
    vector<vector<int>> output;
    int k,n;
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k=k;
        this->n=n;
        
        for(int i=1; i<=9; i++){
            vector<int> v;
            v.push_back(i);
            dfs(1, v, i);
        }
        return output;
    }
    
    
    void dfs(int count, vector<int> v, int sum){
        
        if(sum > n) 
            return;
        
        if(count==k && sum==n){
            output.push_back(v);
            return;
        }
        else if(count==k && sum!=n)
            return;
        
        
        for(int i=v.back()+1; i<=9; i++){
            v.push_back(i);
            dfs(count+1,v,sum+i);
            v.pop_back();
        }
    }
    
};