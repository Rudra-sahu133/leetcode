
class Solution {
public:
    long long fun(int i, vector<int>& nums, int op1, int op2, int k,
                  vector<vector<vector<long long>>>& dp) {

        int n = nums.size();

        if (i == n) {
            return 0;
        }

        if (dp[i][op1][op2] != -1) {
            return dp[i][op1][op2];
        }

        long long x = nums[i];

        // Choice 1: No operation
        long long ans = x + fun(i + 1, nums, op1, op2, k, dp);

        // Choice 2: Only Operation 1
        if (op1 > 0) {
            long long val = (x + 1) / 2;

            ans = min(ans, val + fun(i + 1, nums, op1 - 1, op2, k, dp));
        }

        // Choice 3: Only Operation 2
        if (op2 > 0 && x >= k) {
            long long val = x - k;

            ans = min(ans, val + fun(i + 1, nums, op1, op2 - 1, k, dp));
        }

        // Choice 4: Both operations
        if (op1 > 0 && op2 > 0) {

            long long both = LLONG_MAX;

            // Operation 1 first, then Operation 2
            long long half = (x + 1) / 2;

            if (half >= k) {
                both = min(both, half - k);
            }

            // Operation 2 first, then Operation 1
            if (x >= k) {
                both = min(both, (x - k + 1) / 2);
            }

            if (both != LLONG_MAX) {
                ans = min(ans, both + fun(i + 1, nums, op1 - 1, op2 - 1, k, dp));
            }
        }

        return dp[i][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {

        int n = nums.size();

        vector<vector<vector<long long>>> dp(
            n,
            vector<vector<long long>>(
                op1 + 1,
                vector<long long>(op2 + 1, -1)
            )
        );

        return fun(0, nums, op1, op2, k, dp);
    }
};
