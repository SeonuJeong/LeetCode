class Solution {
public:
    bool checkValidString(string s) {
     
        vector<int> left;
        vector<int> star;
        
        for(int i=0; i<s.length(); i++){
            
            if(s[i]=='(')
                left.push_back(i);
            else if(s[i]=='*')
                star.push_back(i);
            else if(s[i]==')'){
                if(!left.empty()) left.pop_back();
                else if(!star.empty()) star.pop_back();
                else return false;
            }
            
            
        }
        
        while(!left.empty()){
            if(!star.empty() && left.back()<star.back()){
                left.pop_back();
                star.pop_back();
            }
            else{
                break;
            }
        }
        
        if(left.empty()) return true;
        else return false;
    }
};