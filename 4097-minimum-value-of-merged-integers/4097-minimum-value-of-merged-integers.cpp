class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size() ;
        int ans = INT_MAX ;
        for (int i=0 ; i<n ; i+=2) {
            int k  = nums[i+1] ;
            int len = 0 ;
            while (k) {
                len = len +1 ;
                k = k / 10 ;
            }
            ans = min(ans , (nums[i]*((int)(pow(10,len)))) + nums[i+1]);
        }
        return ans ;
    }
};