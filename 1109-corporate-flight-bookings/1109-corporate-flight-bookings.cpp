class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& nums, int n) {
        vector<int> res(n , 0);
        int k = nums.size() ;
        for (int i=0 ; i<k ; i++){
            int l = nums[i][0]-1;
            int r = nums[i][1]-1;
            res[l] += nums[i][2];
            if (r+1 <= n-1){
                res[r+1] -= nums[i][2];
            }
        }

        for (int i=1 ; i<n ; i++){
            res[i] = res[i-1] + res[i];
        }
        return res;
    }
};