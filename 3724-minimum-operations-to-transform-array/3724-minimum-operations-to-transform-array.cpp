class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> df(n) ;
        long long sum = 0;
        for (int i=0 ; i<n ;i++) {
            df[i] = nums1[i] - nums2[i];
            sum += abs(df[i] + 0LL);
        }
        long long mn1 = LLONG_MAX ;
        for (int i=0 ; i<n ; i++) {
            mn1 = min(mn1 , abs( 0LL + nums2[n] - nums1[i]));
            mn1 = min(mn1 , abs(0LL + nums2[n] - nums2[i]));
        }
        for (int i=0 ; i<n ; i++){
            int tt = nums2[n];
            int mn = min(nums2[i] , nums1[i]);
            int mx = max(nums2[i] , nums1[i]);
            if (nums2[n] >= mn && nums2[n] <= mx){
                mn1 = 0;
                break;
            }
        }
        return sum + mn1 + 1 ;


    }
};