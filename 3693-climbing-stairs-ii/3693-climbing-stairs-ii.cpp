class Solution {
public:
    int fun (int i ,int c ,  int n , vector<int>& costs ) {
        if (i == n-1) return c;
        int a = INT_MAX;
        int b = INT_MAX;
        int c1 = INT_MAX;
        if (i < n-1){
            a = fun (i+1 , c + costs[i+1] + 1 , n , costs);
        }
        if (i< n-2) {
            b = fun (i+2 , c + costs[i+2] + 4 , n, costs) ;
        }
        if (i<n-3) {
            c1 = fun (i+3 , c+ costs[i+3] + 9, n  , costs) ;
        }
        return min({a,b,c1});
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> nums(n+1) ;
        nums.push_back(0) ;
        for (int i=0 ; i<n ; i++) {
            nums[i+1] = costs[i];
        }
        vector<int> dp(n+1 , 0);
        for (int i=1 ; i<n+1 ; i++) {
            int a = INT_MAX;
            int b = INT_MAX; 
            int c = INT_MAX;
            if (i-1 >=0 ){
                a = dp[i-1] + costs[i-1] + 1 ;
            }
            if (i-2 >= 0){
                b = dp[i-2] + costs[i-1] + 4 ;
            }
            if (i-3 >=0 ){
                c = dp[i-3] + costs[i-1] + 9 ;
            }

            dp[i] = min({a,b,c});
        } 
        return dp[n] ;
    }
};