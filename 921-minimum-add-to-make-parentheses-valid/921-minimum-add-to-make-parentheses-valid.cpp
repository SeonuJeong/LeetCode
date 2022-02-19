class Solution {
public:
    //08:15
    int minAddToMakeValid(string s) {
        vector<char> stk;
        
        int count=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                stk.push_back('(');
            }
            else{
                if(!stk.empty()) stk.pop_back();
                else count++;
            }
        }
        
        count += stk.size();
        
        return count;
    }
};