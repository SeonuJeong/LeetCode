class Solution {
public:
    //04:55
    int N;
    vector<string> result;
    
    vector<vector<char>> alpa ={ {}, {}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
    
    vector<string> letterCombinations(string digits) {
        unordered_map<int,int> um;
        N = digits.length();
        
        if(digits.length()==0)
            return vector<string>(0);
        /*for(int i=0 ; i<digits.length(); i++){
            if(um.find(digits[i]-'0')==um.end()){
                um.insert(make_pair(digits[i]-'0',1));
            }
            else{
                um[digits[i]-'0']++;
            }
        }//for*/
        
        backTrack(digits, "");
        
        return result;
    }
    
    /*void backTrack(unordered_map<int,int>& um, string combination){
        
        if(combination.length() == N){
            result.push_back(combination);
            return;
        }
        
        for (auto iter = um.begin(); iter != um.end(); ++iter){
            if(iter->second==0) continue;
            
            iter->second--;
            for(int i=0; i<alpa[iter->first].size(); i++){
                backTrack(um,combination+alpa[iter->first][i]);
            }
            iter->second++;
        }
           

    }*/
    
    void backTrack(string digits, string combination){
        
        if(combination.length() == N){
            result.push_back(combination);
            return;
        }
        
        /*for (auto iter = um.begin(); iter != um.end(); ++iter){
            if(iter->second==0) continue;
            
            iter->second--;
            for(int i=0; i<alpa[iter->first].size(); i++){
                backTrack(um,combination+alpa[iter->first][i]);
            }
            iter->second++;
        }*/
         
        for(int i=0; i<alpa[digits[0]-'0'].size(); i++){
                backTrack(digits.substr(1,digits.length()-1),combination+alpa[digits[0]-'0'][i]);
        }

    }
};