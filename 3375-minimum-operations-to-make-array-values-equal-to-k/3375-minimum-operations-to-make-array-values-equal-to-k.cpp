class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size() ;
        map<int,int> my;
        for (int i=0 ; i<n  ;i++ ){
            my[nums[i]]++;
        }
        int ans = 0;
        for (auto it : my){
            if (it.first < k){
                return -1;
            }
            else {
                if (it.first == k){
                    ans = 1;
                }
            }
        }
        if (ans == 1) return my.size() - 1;
        return my.size() ;
    }
};