class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        vector<int> alpaS1(26,0);
        vector<int> alpaS2(26,0);
        
        if(s1.length()>s2.length())
            return false;
        
        for(int i=0; i<s1.length(); i++){
            alpaS1[s1[i]-'a']++; alpaS2[s2[i]-'a']++; 
        }
        
        for(int i=0; i<s2.length()-s1.length(); i++){
            if(isMatch(alpaS1, alpaS2))
                return true;
            
            alpaS2[s2[i+s1.length()]-'a']++;
            alpaS2[s2[i]-'a']--;
        }
        
        return isMatch(alpaS1,alpaS2);
        
    }
    
    bool isMatch(vector<int>& alpaS1, vector<int>& alpaS2){
        for(int i=0; i<alpaS1.size(); i++){
            if(alpaS1[i]!=alpaS2[i])
                return false;
        }
        return true;
    }
};