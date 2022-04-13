class Solution {
public:
    
    string matchPair[5][2] ={{"0","0"},{"1","1"},{"6","9"},{"8","8"},{"9","6"}};
    string matchOne[3] = {"0","1","8"};
    int n;
    vector<string> result;
    vector<string> findStrobogrammatic(int n) {
        this->n = n;
        
        bool isOne=false;
        if(n%2==1)
            isOne = true;
        
        make("",isOne);
        return result;
    }
    
    void make(string output, bool isOne){
        
        if(output.length()==n){
            result.push_back(output);
            return;
        }
        
        
        if(isOne){
            for(int i=0; i<3; i++){
                string s = output+matchOne[i];
                make(s,false);
            }
        }
        else{
            for(int i=0; i<5; i++){
                if(n-output.length()==2 && i==0) continue; 
                string s = matchPair[i][0] + output + matchPair[i][1];
                make(s,false);
            }
        }
        
        
    }
    
};