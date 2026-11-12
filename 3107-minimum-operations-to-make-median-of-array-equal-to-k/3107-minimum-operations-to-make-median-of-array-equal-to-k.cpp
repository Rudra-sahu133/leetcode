class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        if (n % 2 != 0) {
            for (int i = 0; i < n / 2; i++) {
                if (nums[i] <= k) {

                } else {
                    ans += nums[i] - k;
                    nums[i] = k;
                }
            }
            if (nums[n / 2] != k) {
                ans += abs(nums[n / 2] - k);
            }
            for (int i = n / 2 + 1; i < n; i++) {
                if (nums[i] >= k) {

                } else {
                    ans += k - nums[i];
                    nums[i] = k;
                }
            }
            return ans;
        }

        for (int i = 0; i < n / 2 ; i++) {
            if (nums[i] <= k) {

            } else {
                ans += nums[i] - k;
                nums[i] = k;
            }
        }
        if (nums[n/2] != k){
            ans += abs(nums[n/2] - k) ;
        }
        for (int i = n / 2 + 1 ; i < n; i++) {
            if (nums[i] >= k) {

            } else {
                ans += k - nums[i];
                nums[i] = k;
            }
        }


        return ans;
    }
};