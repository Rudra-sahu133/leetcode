class Solution {
public:
    double trimMean(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size() ;
        int l = n / 20 ;
        int r = n / 20 ;
        double sum = 0;
        for (int i=l; i< n-r ; i++){
            sum += nums[i];
        }
        n = n - (n / 10) ;
        double mean = sum / ((n)*1.00) ;
        return mean ;


    }
};