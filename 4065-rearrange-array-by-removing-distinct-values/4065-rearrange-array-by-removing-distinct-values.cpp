class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size() ;
        
        vector<int> vec;
        map<int,int> my;
        for (int i=0 ; i<n ; i++){
            my[nums[i]]++;
        }
        for (int i=1; i<= 100; i++) {
            for (int j=1 ; j<= 100 ;j++) {
                if (my[j] > 0){
                    vec.push_back(j);
                    my[j]--;
                }
            }
        }
        return vec ;
    }
};