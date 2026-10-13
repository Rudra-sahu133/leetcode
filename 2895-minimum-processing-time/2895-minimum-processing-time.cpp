class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& tasks) {
        int n = pt.size() ;
        sort(tasks.begin() , tasks.end()) ;
        sort (pt.begin() , pt.end()) ;
        int i = 0 ;
        vector<int> vec;
        for (int i=0; i<4*n ; i+= 4){
            int mx = -1;
            for (int j=i ; j<i+4 ; j++){
                mx = max(mx , tasks[j]) ;
            }
            vec.push_back(mx);
        }
        sort(vec.begin() , vec.end()) ;
        int j = n-1 ;
        int ans = 0;
        while (i<n){
            ans = max(pt[i] + vec[j] , ans);
            i++;
            j--;
        }
        return ans ;

    }
};