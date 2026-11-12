class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size() ;
        int ans1 =  1;
        int cnt = 1 ;

        for (int i=0 ; i<n-1 ; i++) {
            if (nums[i] < nums[i+1]){
                cnt++;
            }
            else {
                
                ans1 = max(ans1 , cnt) ;
                cnt = 1 ;
            }
        }
        ans1 = max(ans1 , cnt) ;

        cnt = 1 ;
        int ans2 = 0 ;
        for (int i=0 ; i<n-1 ;i++) {
            if (nums[i] > nums[i+1]){
                cnt++;
            }
            else {
                
                ans2 =  max(ans2 , cnt);
                cnt = 1 ;
            }
        }
        ans2 = max(ans2 , cnt) ;

        return max(ans1 , ans2) ;
    }
};