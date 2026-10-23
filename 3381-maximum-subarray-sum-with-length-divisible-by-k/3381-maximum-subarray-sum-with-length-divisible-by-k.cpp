class Solution {
public:
        long long maxS(vector<long long> nums1) {
        long long sum = nums1[0];
        long long maxi = nums1[0];

        for (int i = 1; i < nums1.size(); i++) {
            sum = max(nums1[i] + 0LL, 0LL + sum + nums1[i]);
            maxi = max(maxi, sum);
        }

        return maxi;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pf(n);
        pf[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pf[i] = pf[i - 1] + nums[i] + 0LL;
        }
        map<int, vector<long long>> my;
        for (int i = 0; i < n; i++) {
            if (i - k + 1 >= 0) {
                my[i % k].push_back(pf[i] - (i - k >= 0 ? pf[i - k] : 0));
            }
        }
        long long ans = LLONG_MIN;
        for (auto it : my) {
            vector<long long> vec = it.second;
            ans = max(ans , maxS(vec)) ;
        }
        return ans ;
    }
};