class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> m;
        
        for(int i=0; i<arr.size(); i++){
            if(m.find(arr[i]) != m.end() && arr[i] == 0)
                return true;
            
            if(m.find(arr[i]) == m.end())
                m.insert(pair<int,int>(arr[i],i));
            
        
        }
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i]==0)
                continue;
            
            if(m.find(arr[i]*2) != m.end()){    
                return true; 
            } 
        }
        return false;
        
    }
};