class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<vector<int>> vec(31 , vector<int> (n , 0));
        
        vector<int> arr(n, 0);
        for(int i=0 ; i<n; i++) {
            int cnt= 0;
            int p = nums[i];
            while (p %2 == 0){
                cnt++;
                p = p / 2 ;
            }
            arr[i] = cnt ;
            vec[cnt][i] += 1 ;
        }

        for (int i=0 ; i<31 ; i++) {
            for (int j=1 ; j<n ; j++) {
                vec[i][j] = vec[i][j] + vec[i][j-1];
            }
        }
        long long ans = 0;

        for (int i=0 ; i<n ; i++) {
            int mn = INT_MAX ;
            long long gc = nums[i] ; 
            for (int j=i ; j<n; j++) {
                gc = __gcd(gc , 0LL + nums[j]) ;
                ans = max(ans , 1LL*gc*((1LL)*(j-i+1))) ;
                mn= min(mn , arr[j]) ;
                if (j-i+1 <= k){
                    ans = max(ans , 2*1LL*gc*((1LL)*(j-i+1))) ;

                }
                else {
                    if (vec[mn][j] - (i>= 1 ? vec[mn][i-1] : 0) <= k){
                        ans = max(ans , 2*1LL*gc*((1LL)*(j-i+1))) ;

                    }
                }

            }
        }
        return ans ;

    }
};