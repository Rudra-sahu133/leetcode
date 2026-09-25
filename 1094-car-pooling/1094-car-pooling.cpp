class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cp) {
        int n = trips.size();

        vector<int> df(1001 , 0) ;
        for (int i=0 ; i<n ; i++) {
            int l = trips[i][1];
            int r = trips[i][2];
            int p  = trips[i][0];
            df[l] += p ;
            if (r+1 < 1001){
                df[r] += -p;
            }

        }
        for (int i=1 ; i<1001 ;i++ ){
            df[i] = df[i-1] + df[i] ;
        }
        for (int i=0 ; i<1001 ; i++){
            if (df[i] > cp){
                return false;
            }
        }
        return true ;

    }
};