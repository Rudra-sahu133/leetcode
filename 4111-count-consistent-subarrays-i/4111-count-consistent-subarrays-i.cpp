class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int ans = 0 ;
        for (int i=0 ; i<n ; i++) {
            int mn = nums[i] ; 
            int ad = 127 ;
            for (int j=i ; j<n ; j++) {
                ad = ad & nums[j] ;
                mn = min(mn , nums[j]);
                if (mn == ad){
                    ans++;
                }
            }
        }
        return ans ;
    }
};