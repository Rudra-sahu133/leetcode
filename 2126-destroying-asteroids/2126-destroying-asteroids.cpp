class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int> &nums) {
        sort(nums.begin() , nums.end()) ;
        int n = nums.size() ;
        long long curr = mass ;
        for (int i=0 ; i<n; i++ ){
            if (curr >= nums[i]){
                curr += nums[i] + 0LL;
            }
            else return false;
        }
        return true ;
    }
};