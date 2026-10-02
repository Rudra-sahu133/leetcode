class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        map<int,int> my;

        for (int x : nums) {
            my[x]++;
        }

        int mn = INT_MAX;

        for (auto it : my) {
            mn = min(mn, it.second);
        }

        int ans = INT_MAX;

        for (int j = 1; j <= mn; j++) {

            int cnt = 0;
            bool ok = true;

            for (auto it : my) {
                int p = it.second;

                int groups = (p + j) / (j + 1);

                if (groups * j > p) {
                    ok = false;
                    break;
                }

                cnt += groups;
            }

            if (ok) {
                ans = min(ans, cnt);
            }
        }

        return ans;
    }
};