class Solution {
public:
    //0630
    vector<vector<string>> result;
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        for(int i=0; i<strings.size(); i++){
            makeGroup(strings[i]);
        }
        
        return result;
    }
    
    void makeGroup(string s){
        int len = result.size();
        
        bool isInserted=false;
        for(int i=0; i<len; i++){
            if(s.length()!=result[i][0].length())
                continue;
            
            string stand = result[i][0];
            bool check = false;
            for(int j=1; j<stand.length(); j++){
                int before = stand[j-1]>s[j-1]?26-stand[j-1]+s[j-1]: s[j-1]-stand[j-1];
                
                int after = stand[j]>s[j]?26-stand[j]+s[j]: s[j]-stand[j];
            
                if(before != after){
                    check=true;   break;   
                }
            }
            
            if(check) continue;
            else{
                result[i].push_back(s);
                isInserted=true;
                break;
            }
        }
        
        if(!isInserted){
            result.push_back(vector<string> (0));
            result.back().push_back(s);
        }
    }
    
    
};