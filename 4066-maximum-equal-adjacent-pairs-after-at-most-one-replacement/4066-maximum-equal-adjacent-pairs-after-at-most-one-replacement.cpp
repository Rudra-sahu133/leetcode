class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 1;
        map<pair<int,int> , int> my;
        // map<int,int> my1 ;
        int cnt = 0;
        for (int i=0 ; i<n-1; i++){
            if (nums[i] != nums[i+1]){
                my[{min(nums[i] , nums[i+1]) , max(nums[i] , nums[i+1])}]++;
            }
            else {
                cnt++;
            }
        }

        for (auto it : my){
            ans = max(ans , it.second + cnt) ;
        }
        return max(ans , cnt) ;
        // map<int,int> my;
        // int l = 0;
        // int r = 0 ;
        // int len = 0;
        // while (l<n && r<n) {
        //     my[nums[r]]++;
        //     len = my.size() ;
        //     if (len <= 2){
        //         ans = max(r-l+1 , ans);
        //         r++;
        //     }
        //     while (len > 2){
        //         if (my[nums[l]] > 0) my[nums[l]]--;
        //         if (my[nums[l]] == 0) len--;
        //         l++;
        //     }
            
        // }
        // // for (int i=0;)
        // return ans-1 ;

    }
};