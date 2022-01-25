class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0)
            return false;
        
        double k = (double)n;
        k = log2(k);
        
        if (k/1.00 == (int)k)
            return true;
        else
            return false;
    }
};