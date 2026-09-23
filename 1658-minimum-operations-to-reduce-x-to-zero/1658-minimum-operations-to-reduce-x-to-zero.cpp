class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() ;
        int sum =0 ;
        for (int i=0 ; i<n ; i++) {
            sum += nums[i] ;
        }
        sum = sum - x ;
        if (sum < 0) return -1;
        if (sum == 0) {
            return n ;
        }
        int curr= 0;
        int l =0 ;
        int r = 0;
        int ans = 0;
        while (l < n && r < n ) {
            if (curr < sum){
                curr += nums[r];
                r++;
            }
            if (curr == sum) {
                ans = max(ans , r-l) ;
                
                curr = curr - nums[l];
                l++;
            }
            
                while (l < r && curr > sum  ){
                    curr = curr - nums[l];
                    l++;
                }
            
        }
        if (curr == sum) {
            ans = max(ans , r-l) ;

        }
        if (ans == 0) return -1;
        return n - ans ; 


    }
};