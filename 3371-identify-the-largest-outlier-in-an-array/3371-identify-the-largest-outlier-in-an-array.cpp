class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0;
        map<int,int> my;
        for (int i=0 ; i<n ;i++) {
            sum += nums[i];
            my[nums[i]]++;
        }
        int y = INT_MIN ;
        // for (int i=0 ; i<n ; i++){
        //     if ((sum - nums[i]) % 2 ==0 && my[(sum - nums[i])/2] > 0 ){
                
        //         y = max(y , nums[i]);
        //     }
        // }

        for (int i=0 ; i<n ; i++){
            int rq = -1;
            if (sum == 3*nums[i]){
                rq = 2 ;
            }
            else rq = 1 ;
            if (my[(sum - 2*nums[i])] >= rq){
                y = max(y , sum - 2*nums[i]);
            }
        }
        return y ;
    }
};