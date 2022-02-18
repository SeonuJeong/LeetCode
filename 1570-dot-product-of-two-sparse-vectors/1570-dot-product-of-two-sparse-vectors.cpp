class SparseVector {
public:
    
    public: vector<int> spare;
    SparseVector(vector<int> &nums) {
        spare = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        vector<int> other = vec.spare;
        int sum=0;
        for(int i=0; i<spare.size(); i++){
            sum += spare[i]*other[i];
        }
        
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);