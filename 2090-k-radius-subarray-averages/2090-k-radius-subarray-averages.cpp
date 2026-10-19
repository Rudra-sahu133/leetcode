class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size() ;
        int len = 2*k + 1 ;
        vector<int> ans(n , -1) ;
        long long sum = 0 ;
        for (int i=0 ; i<min(n , len) ;i++) {
            sum += nums[i] + 0LL;
        }
        int l = 0 ;
        int r = 2*k ;
        while (r<n) {
            ans[(l+r)/2] = sum / len ;
            sum = sum - nums[l];
            sum = sum + (r+1 < n ? nums[r+1] : 0) ;
            l++;
            r++;
        }
        return ans ;

    }
};