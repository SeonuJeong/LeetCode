class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        vector<string> result;
        if(s.length()<=10)
            return result;
        
        for(int i=0; i<=s.length()-10; i++){
            map<string,int>::iterator it = m.find(s.substr(i,10));
            if(it!=m.end()&&it->second == 0){ // 있다.
                result.push_back(s.substr(i,10));
                it->second = 1;
            }
            else{
                m.insert(pair<string,int>(s.substr(i,10),0));
            }
        }
        return result;
    }
};