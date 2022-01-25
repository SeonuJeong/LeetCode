class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> ones;
        for(int i=0; i<seats.size(); i++){
            if(seats[i]==1)
                ones.push_back(i);
        }
        
        int dis=0;
        if(ones.size()==1){
            int tmp = (seats.size()-1-ones[0]);
            dis = max(ones[0], tmp );
        }
        else{
            int tmp = (seats.size()-1-ones.back());
            dis = max(ones[0], tmp);
        }
        
        for(int i=1;i<ones.size(); i++){
            
            int mid = (ones[i] + ones[i-1])/2;
            
            int madis = min(mid-ones[i-1],ones[i]-mid);
            
            dis = max(dis,madis);
        }
        
        return dis;
    }
};