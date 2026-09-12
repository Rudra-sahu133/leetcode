class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0;
        for (int i=0 ; i<n; i++) {
            int pd = 1 ;
            int gc = nums[i] ;
            int lc = nums[i];
            for (int j=i ; j<n ; j++){
                pd = pd * nums[j];
                gc = __gcd(nums[j] , gc) ;
                lc = lcm (nums[j] , lc) ;
                if(pd > gc*lc) break;
                if (pd == gc*lc){
                    ans= max(ans , j-i+1) ;
                }
            }
        }
        return ans;
    }
};