class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        
        int index=0;
        string common="";
        while(index<strs[0].size() && index<strs[1].size()){
            if(strs[0][index] == strs[1][index]){
                common += strs[0][index];
            }
            else{
                break;
            }
            index++;
        }
        
        
        for(int i=2; i<strs.size(); i++){
            int cur=0;
            string cm="";
            
            while(cur<strs[i].size() && cur<common.size()){
                if(common[cur] == strs[i][cur]){
                    cm += strs[i][cur];
                }
                else{
                    break;
                }
                cur++;
            }
            
            if(cm.length()==0)return cm;
            else common = cm;
        }
        
        return common;
        
    }
};