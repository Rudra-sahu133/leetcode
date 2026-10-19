class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans ;
        int idx = 0;
        int cnt = 0;
        int n = nums.size() ;
        for (int i=0; i<n ; i++) {
            if (nums[i] < target){
                idx++ ;
            }
            else if (nums[i] == target) {
                cnt++;
            }
        }
        for (int i=0 ; i<cnt ; i++){
            ans.push_back(i + idx);
        }
        return ans; 
    }
};