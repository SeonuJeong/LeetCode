class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        vector<int> stk;
        
        for(string s: tokens){
            int N = stk.size()-1;
            
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                int ri = stk.back();
                stk.pop_back();
                int le = stk.back();
                stk.pop_back();
                
                stk.push_back(cal(le,ri,s));
            }
            else{
                stk.push_back(stoi(s));
            } 
        }
        
        return stk.back();
    }
    
    int cal(int le, int ri, string op){
        
        if(op=="+")return le+ri;
        else if(op=="-")return le-ri;
        else if(op=="*")return le*ri;
        else if(op=="/")return le/ri;
        
        return -1;
    }
};