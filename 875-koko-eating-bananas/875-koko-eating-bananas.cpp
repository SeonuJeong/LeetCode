class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ri=0, le=1;
        for(int i=0; i<piles.size();i++){
            ri = max(ri,piles[i]);
        }
        
        //todo case 2 : piles.size()==h
        if(piles.size()==h)
        return ri;
        
        //todo case 3 : piles.size()>h
        int k = INT_MAX;
        while(le<ri){
            
            int mid = le + (ri-le)/2;
            int count=0;
            
            for(int i=0; i<piles.size(); i++){
                count+=piles[i]/mid+(piles[i]%mid!=0);
                if(count>h){ break;}
            }
            
            if(count<=h){
                //k = min(mid,k);
                // try to minimize k
                ri = mid;
            }
            else{
                le=mid+1;
            }
        }//end while(le<ri)
        
        return ri;
        
    }//end int minEatingSpeed(vector<int>& piles, int h)
};