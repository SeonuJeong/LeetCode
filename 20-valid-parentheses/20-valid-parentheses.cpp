class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        
        for(char c: s){
            if(c=='(' || c=='[' || c=='{'){
                stk.push_back(c);
            }
            else if(stk.size()!=0){
                if((stk.back()=='(' && c==')') || (stk.back()=='[' && c==']') || (stk.back()=='{' && c=='}')){
                    stk.pop_back();
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        
        if(stk.size()!=0)return false;
        
        return true;
    }
};