#define ll long long 
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for ( ll i=0 ; i<nums.size() ; i++) {
            if ( nums[i] < 0) nums[i] = -nums[i];
        }
        ll n = nums.size();
        sort(nums.begin(),nums.end());
        ll pos = 0 ;
        ll neg = 0 ;
        for ( int i=0  ; i<n/2 ; i++) {
            neg = neg + (nums[i]*nums[i]);
        }
        for ( int i=n/2  ; i<n ; i++) {
            pos = pos + (nums[i]*nums[i]);
        }
        return pos - neg;
    }
};