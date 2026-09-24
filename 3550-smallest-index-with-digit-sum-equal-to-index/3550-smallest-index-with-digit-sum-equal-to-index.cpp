class Solution {
public:
    int smallestIndex(vector<int>& arr) {
        int n = arr.size();
        for( int i=0 ; i<n ; i++){
            int dg = 0 ;
            int t = arr[i];
            while(t != 0 ){
                dg = dg + t%10 ;
                t /= 10 ;

            }
            if ( i == dg ){
                return i ;
            }
        }
        return -1;
    }
};