class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {    
        
        vector<int> result(length,0);
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > start;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > end;
        
        for(vector<int> v:updates){
            start.push(make_pair(v[0],v[2]));
            end.push(make_pair(v[1],v[2]));
        }
        
        
        
        int sum=0;
        for(int i=0; i<length; i++){
            
            while(!start.empty()&&start.top().first==i){
                sum += start.top().second;
                start.pop();
            }
            
            while(!end.empty()&&end.top().first<i){
                sum -= end.top().second;
                end.pop();
            }
            
            result[i] = sum;
        }
        
        return result;
    }
};