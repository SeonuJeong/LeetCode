class Solution {
public:
    // 01:30
    // 02:15
    vector<vector<int>> cache;
    string word1;
    string word2;
    int minDistance(string word1, string word2) {
        cache.assign(word1.size(), vector<int>(word2.size(),-1));
        this->word1 = word1;
        this->word2 = word2;
        
        return dp(0, 0);
    }
    
    int dp(int w1, int w2){
        
        if(w1>=word1.length() && w2>=word2.length()){
            return 0;
        }
        else if(w1>=word1.length() || w2>=word2.length()){
            return (word2.length()-w2)+(word1.length()-w1);
        }
        
        
        if(cache[w1][w2] != -1){
            return cache[w1][w2];
        }
        
        int result;
        if(word1[w1]!=word2[w2]){
            result = min(dp(w1+1,w2+1)+1, dp(w1+1,w2)+1);
            result = min(result, dp(w1,w2+1)+1);
        }
        else{
            result = dp(w1+1,w2+1);
        }
        
        cache[w1][w2] = result;
        
        return result;
    }
};