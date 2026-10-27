class Solution {
public:
    int minLights(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> df(n , 0) ;
        for (int i=0 ; i<n ; i++) {
            if (nums[i] > 0) {
                df[max(0 , i - nums[i])] += 1 ;
                if (i+nums[i]+1 < n){
                    df[i+nums[i] + 1] += -1 ;
                }
            }
        }
        for (int i=1 ; i<n ; i++) {
            df[i] = df[i-1] + df[i] ;
        }
        int c=  0;
        int ans = 0 ;
        for (int i=0 ; i<n; i++) {
            if (df[i] == 0){
                c++;
            }
            else {
                ans += (c + 2) / 3 ;
                c = 0;
            }
        }
        ans += (c+2) / 3;
        return ans ;

    }
};