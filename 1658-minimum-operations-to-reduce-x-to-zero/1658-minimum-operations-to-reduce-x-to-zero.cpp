class Solution {
public:
    int find (vector<int> &pf , int l , int r , int p) {
        while (l<=r) {
            int m = l + (r-l)/2 ;
            if (pf[m] == p) return m;
            else if (pf[m] < p){
                l = m + 1 ;
            }
            else {
                r = m - 1 ;
            }
        }
        return -1 ;
    }
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() ;
        vector<int> pf(n) ;
        // vector<int> sf(n) ;
        pf[0] = nums[0];
        // sf[n-1] = nums[n-1];
        for (int i=1 ; i<n ; i++){
            pf[i] = pf[i-1] + nums[i];
        }
        // for (int i=n-2 ; i>=0 ; i--) {
        //     sf[i]  = sf[i+1] + nums[i];
        // }
        int ans = INT_MAX ;
        int idx = find(pf , 0 , n-1 , x);
        if (idx != -1){
            ans = min(ans , idx + 1) ;
        }
        int curr= 0;
        for (int i=n-1 ; i >=0  ; i-- ) {
            curr += nums[i] ;
            if (curr == x){
                ans = min(ans , n-i);
            }
            if (curr > x) break;
            int idx = find(pf , 0 , i-1 , x - curr) ;
            if (idx != -1){
                ans = min(ans , n-i + idx  + 1) ;
            }
        }
        if (ans == INT_MAX) return -1;
        return ans ;
    }
};