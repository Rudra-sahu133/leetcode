class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans;
        for (int i=0 ; i<n ; i++){
            int mn = INT_MAX;
            for (int j=i+1 ; j<n ;j++){
                if (nums[j] <= nums[i]){
                    mn= nums[j];
                    break;
                }
            }
            if(mn == INT_MAX) ans.push_back(nums[i]);
            else ans.push_back(nums[i] - mn);

        }
        return ans ;
    }
};