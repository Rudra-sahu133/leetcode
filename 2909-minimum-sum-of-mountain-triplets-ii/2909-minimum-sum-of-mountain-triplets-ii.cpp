class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n= nums.size() ;
        long long sum = LONG_MAX;
        
        vector<int> pf(n) , sf(n) ;
        pf[0] = nums[0];
        sf[n-1] = nums[n-1];
        for (int i=1 ; i<n ; i++){
            pf[i] = min(pf[i-1] ,nums[i] );
        }
        for (int i=n-2 ; i>=0 ; i--){
            sf[i] = min(sf[i+1] , nums[i]);
        }

        for (int i=1 ; i<=n-2 ;i++){
            if (nums[i] > pf[i-1] && nums[i] > sf[i+1]){
                sum = min(sum ,0LL +  nums[i] + pf[i] + sf[i+1]);
            }
        }
        

        if (sum == LONG_MAX) return -1;
        return sum ;
    }
};