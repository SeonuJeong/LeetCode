class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        
        for(int val : asteroids){
            if(stk.empty() || !(stk.back()>0&&val<0)){ 
                stk.push_back(val);
                continue;
            }
            bool flag=false;
            while(stk.size()>0 && abs(stk.back())<=abs(val) 
                 && stk.back()*val<0){      

                if(abs(stk.back())==abs(val)){   
                    stk.pop_back();
                    flag=true;
                    break;
                }
                stk.pop_back();
            }
            
            if(flag) continue;
            
            if( stk.empty() || !(stk.back()>0&&val<0)) { 
                stk.push_back(val);
            }
            
        }
        
        return stk;
    }
};