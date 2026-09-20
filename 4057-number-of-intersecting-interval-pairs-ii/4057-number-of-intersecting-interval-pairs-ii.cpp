class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& arr) {
        int n = arr.size() ;
        vector<int> st(n);
        for (int i=0 ; i<n; i++){
            st[i]=arr[i][0];
        }
        sort(st.begin() ,st.end());
        long long N = n;
        long long tt = ((N)*(N-1)) / 2 ;
        long long cnt= 0;
        for (int i=0 ; i<n ; i++){
            int end = arr[i][1];
            auto it = upper_bound(st.begin(), st.end() , end);
            cnt += (st.end() - it);
        }
        return ( tt- cnt) ;
    }};