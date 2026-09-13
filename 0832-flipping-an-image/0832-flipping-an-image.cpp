class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& nums) {
        int n = nums.size() ;
        int m = nums[0].size() ;
        for (int i=0 ; i<n ; i++){
            reverse(nums[i].begin() , nums[i].end());
        }
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                nums[i][j] = 1 - nums[i][j];
            }
        }
        return nums ;
    }
};