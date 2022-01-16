class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int i=0, j=0;
        vector<int> result;
        while(i<nums1.size()&&j<nums2.size()){
            
            if(nums1[i]==nums2[j]){
                int tmp = nums1[i];
                result.push_back(tmp);
                
                while(nums1[i]==tmp){
                    i++; 
                    if(i==nums1.size())break;
                }
                    
                
                while(nums2[j]==tmp){
                    j++;
                    if(j==nums2.size())break;
                }
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
        }
        
        return result;
    }
};