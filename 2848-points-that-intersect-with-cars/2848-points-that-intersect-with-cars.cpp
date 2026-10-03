class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size() ;
        int cnt =0 ;
        sort(nums.begin() , nums.end());
        int l = nums[0][0];
        int r = nums[0][1];
        cnt += r - l + 1 ;
        for (int i=1 ; i<n ; i++) {
            if (nums[i][0] <= r){
                if (nums[i][1] <= r){
                }
                else {
                    cnt +=  nums[i][1] - r ;
                }
                r = max(r , nums[i][1]);
            }
            else {
                cnt += nums[i][1] - nums[i][0] + 1 ;
                l = nums[i][0] ;
                r = nums[i][1];
            }
        }
        return cnt ;
    }
};