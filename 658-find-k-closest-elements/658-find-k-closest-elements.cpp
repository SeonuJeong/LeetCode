class Solution {
public:
    
struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first)
            return a.second > b.second;
        
        return a.first>b.first;
    }
};
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        
        for(int i=0; i<arr.size(); i++){
            pq.push(make_pair(abs(x-arr[i]),arr[i]));
        }
        
        
        vector<int> result;
        
        for(int i=0; i<k; i++){
            
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};