class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int pressed = 0;
        int j=0;
        int i=0;
        while(i<name.size()){
            int _j=j, _i=i;
            while(typed[j] == typed[_j])
                if(_j+1<typed.size())
                    _j++;
                else{
                    _j++; break;}
             
            while(name[i]==name[_i])
                if(_i+1<name.size())
                    _i++;
                else{
                    _i++; break;}
            
            if(typed[j]!=name[i])
                return false;
            
            if(_j-j<_i-i)
                return false;
            
            j = _j;
            i = _i;
        }
        
        if(j==typed.size() && i==name.size())
            return true;
        else
            return false;
    }
};