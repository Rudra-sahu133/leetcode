
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> pf(n) ;
        map<int,int> my1;
        for (int i=0 ; i<n ; i++) {
            my1[nums[i]]++;
            if ((my1[nums[i]] > (i+1) / 2)  ){
                pf[i] = nums[i];
            }
            else if (i-1 >= 0 && my1[pf[i-1]] > (i+1) / 2){
                pf[i] = pf[i-1] ;
            }
            else {
                pf[i] = -1 ;
            }
        }

        my1.clear() ;
        vector<int> sf(n) ;
        for (int i=n-1 ; i>=0 ; i--) {
            my1[nums[i]]++;
            if (my1[nums[i]] > (n-i) / 2){
                sf[i] = nums[i];
            }
            else if (i+1 < n && my1[sf[i+1]] > (n-i) / 2){
                sf[i] = sf[i+1] ;
            }
            else {
                sf[i] = -1;
            }
        }

        for (int i=0 ; i<n-1 ; i++){
            if (pf[i] == sf[i+1] && pf[i] != -1 && sf[i+1] != -1){
                return (int)i ;
            }
        }
        return -1 ;
    }
};