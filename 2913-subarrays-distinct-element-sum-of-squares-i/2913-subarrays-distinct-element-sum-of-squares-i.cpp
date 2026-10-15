class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0;
        for(int i=0 ; i< n ; i++) {
            map<int,int> my;
            for (int j=i ; j<n ; j++) {
                my[nums[j]]++;
                ans += (my.size())*(my.size()) ;
            }
        }
        return ans;
    }
};