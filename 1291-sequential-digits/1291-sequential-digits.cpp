class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string nums = "0123456789";
        
        int low_digit = calDigit(low);
        int high_digit = calDigit(high);
        int cur_digit = low_digit;
        
        int le,ri;
        
        vector<int> result;
        
        while(cur_digit<=high_digit){
            le = 1; ri = cur_digit;
            string flag = "right";
            
            while(ri<nums.length() && le > 0 ){
                
                if(flag == "right"){
                    int val = stoi(nums.substr(le,ri-le+1));
                    if(val>=low && val<=high)
                        result.push_back(val);
                    else if(val>high){
                        flag ="left";
                        int dif = ri-le;
                        ri = le; le = ri-dif;
                    }
                    le++; ri++;
                }
                else if(flag == "left"){
                    string tmp = nums.substr(le,ri-le+1);
                    reverse(tmp.begin(), tmp.end());
                    int val = stoi(tmp);
                    if(val>=low && val<=high)
                        result.push_back(val);
                    le--; ri--;
                }
                
            } // while(ri<nums.length() && le > 0 )
            
            cur_digit++;
            
        } //while(cur_digit<=high_digit)
        
        return result;
    }
    
    int calDigit(int n){
        int count=0;
        while(n!=0){
            n = n/10;
            count++;
        }
        return count;
    }
};