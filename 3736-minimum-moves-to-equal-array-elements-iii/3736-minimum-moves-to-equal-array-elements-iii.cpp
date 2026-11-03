class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;
        int ans = 0 ;
        for (int i=0 ; i<n ; i++) {
            sum = max (sum , nums[i]) ;
        }
        for (int i=0 ; i<n ; i++) {
            ans += sum - nums[i] ;
        }
        return ans ;
    }
};