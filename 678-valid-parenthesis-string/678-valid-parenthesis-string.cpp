class Solution {
public://0830
    bool checkValidString(string s) {
        vector<int> paren;
        vector<int> star;
        
        
        for(int i=0; i<s.length(); i++){
            
            if(s[i]=='('){
                paren.push_back(i);
            }
            else if(s[i]==')'){
                if(!paren.empty())
                    paren.pop_back();
                else if(!star.empty())
                    star.pop_back();
                else
                    return false;
            }
            else if(s[i]=='*'){
                star.push_back(i);
            }
        }
        
        
        for(int i=paren.size()-1; i>=0; i--){
            if(!star.empty()&&paren[i]<star.back())
                star.pop_back();
            else
                return false;
        }
        
        return true;
        
    }
};