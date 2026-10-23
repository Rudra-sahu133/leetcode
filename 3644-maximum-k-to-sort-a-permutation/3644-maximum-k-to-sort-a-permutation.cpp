class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> vec = nums ;
        sort(vec.begin() , vec.end()) ;
        int ans = pow(2,31) - 1;
        
        for (int i=0 ; i<n ; i++) {
            if (nums[i] != i){
                ans = ans & nums[i];
            }
        }
        if (ans == pow(2,31) - 1) return 0;
        return ans ;
        
    }
};