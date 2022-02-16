class Solution {
public:
    string decodeString(string s) {
        
        vector<int> stk;
        bool stackON=false;
        bool digitON=false;
        int digit;
        int left;
        string result="";
        for(int i=0; i<s.length(); i++){
            if(s[i]>='0' && s[i]<='9' && digitON==false){ // 숫자일 때
                digit = stoi(s.substr(i,s.find("[",i)-i));
                digitON=true;
            }
            else if(s[i]=='['){
                stackON=true;
                stk.push_back(i);
            }
            else if(s[i]==']'){
                left = stk.back();
                stk.pop_back();
            }
            else if(digitON==false){
                result += s[i];
            }
            
            if(stackON && stk.empty()){//decodeString 하위 시작
                string sub = decodeString(s.substr(left+1, i-left-1));
                for(int k=0; k<digit; k++){
                    result += sub;
                }
                stackON=false; digitON=false;
            }
        }
        return result;
    }
};