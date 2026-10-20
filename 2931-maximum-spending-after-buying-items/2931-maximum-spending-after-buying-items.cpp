class Solution {
public:
    long long maxSpending(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        for (int j = 0; j < m; j++) {
            pq.push({nums[j][n - 1], {j, n - 1}});
        }
        long long ans = 0;
        int d = 1;
        while (!pq.empty()) {
            int k = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans += (1LL * k) *( d * 1LL);
            d++;
            pq.pop();
            if (y - 1 >= 0) {
                pq.push({nums[x][y - 1], {x, y - 1}});
            }
        }
        return ans;
    }
};