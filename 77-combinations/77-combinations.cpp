class Solution {
public:
    vector<vector<int>> result;
    int N, K;
    vector<vector<int>> combine(int n, int k) {
        N = n; K = k;
        vector<int> stk;
        func(stk,0);
        return result;
    }
    
    void func(vector<int> stk, int depth){
        if(depth == K){
            result.push_back(stk);
        }
        else{
            int last=0;
            if(stk.size()!=0) last = stk.back();
            
            for(int i=last+1; i<=N; i++){
                stk.push_back(i);
                func(stk,depth+1);
                stk.pop_back();
            }
        }
        return;
    }
    
};