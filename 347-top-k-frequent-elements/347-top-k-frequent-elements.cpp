class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        
        vector<pair<int,int>> v;
        
        unordered_map<int,int>::iterator it = um.begin();
        for( ; it!=um.end(); it++){
            v.push_back(make_pair(it->first, it->second));
        }
        
        int left=0, right=v.size()-1;
        int pivotIndex = v.size();
        while(pivotIndex!=k){
            
            pivotIndex = partition(v, left, right);
            
            if(pivotIndex<k)
                left = pivotIndex;
            else
                right = pivotIndex-1;
        }
        
        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(v[i].first);
        }
        
        return result;
    }
    
    int partition(vector<pair<int,int>>& v,int left, int right){
        int pivot = v[(left+right)/2].second;
        
        while (left < right) {
            // Iterate through the range and swap elements to make sure
            // that all points closer than the pivot are to the left
            if (v[left].second <= pivot) {
                v[left].swap(v[right]);
                right--;
            } else {
                left++;
            }
        }
        
        // Ensure the left pointer is just past the end of
        // the left range then return it as the new pivotIndex
        if (v[left].second > pivot)
            left++;
        
        return left;
    }
};