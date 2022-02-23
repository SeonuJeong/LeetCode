class Solution {
public:
    //05:45
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int i=0;
        for(vector<int> v: points){
            int distance = (v[0]*v[0]) + (v[1]*v[1]);
            pq.push(make_pair(distance,i++));
        }
        
        vector<vector<int>> result;
        for(i=0; i<k; i++){
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return result;
    }
};