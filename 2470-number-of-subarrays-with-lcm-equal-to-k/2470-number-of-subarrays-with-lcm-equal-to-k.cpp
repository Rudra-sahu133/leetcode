class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size() ;
        int cnt = 0;
        for (int i=0 ; i<n ; i++){
            long long lc = 0LL + nums[i];
            if (lc == (k+0LL)) cnt++;
            for (int j=i+1 ; j<n ; j++){
                lc = lcm(lc , 0LL + nums[j]);
                if (lc ==( k + 0LL)) cnt++;
                if (lc > k) break;
            }
        }
        return cnt;
    }
};