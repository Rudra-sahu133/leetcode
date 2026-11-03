class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> pf(n) ;
        vector<int> sf(n) ;

        pf[0] = 1 ;
        sf[n-1] = 1 ;

        for (int i=1 ; i<n ; i++) {
            if (nums[i] >= nums[i-1]){
                pf[i] = pf[i-1]+1;
            }
            else {
                pf[i] = 1 ;
            }
        }
        for (int i=n-2 ; i>=0 ; i--) {
            if(nums[i] <= nums[i+1]) {
                sf[i] = sf[i+1] + 1 ;
            }
            else {
                sf[i] = 1 ;
            }
        }
        int mx = 0 ;
        for (int i=0 ; i<n ; i++) {
            mx = max(mx , pf[i]);
            mx = max(mx, sf[i]) ;

        }
        for (int i=1 ; i<n-1 ; i++) {
            if (nums[i+1] >= nums[i-1]) {
                mx = max(mx , pf[i-1] + sf[i+1] + 1) ;
            }
            else {
                mx = max(mx , pf[i-1] + 1) ;
                mx = max(mx , sf[i+1]  + 1) ;

            }
        }
        if (n >= 2){
            mx = max(mx , sf[1] + 1) ;
            mx = max(mx , pf[n-2] + 1);
        }

        return mx ;
        





    }
};