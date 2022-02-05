class Solution {
public:
    //05:55
    
    vector<string> result;
    int N;
    vector<string> generateParenthesis(int n) {
        N = n;
        backTrack("",0,0);
        return result;
    }
    
    void backTrack(string combi, int left, int right){
        
        if(combi.length() == N*2){
            result.push_back(combi);
            return;
        }
            
        
        if(left == right){
            backTrack(combi+'(',left+1, right);
        }
        else if(left>right){
            if(left==N){
                backTrack(combi+')',left, right+1);
            }
            else{
                backTrack(combi+'(',left+1, right);
                backTrack(combi+')',left, right+1);
            }
        }
        
        return;
    }
    
};