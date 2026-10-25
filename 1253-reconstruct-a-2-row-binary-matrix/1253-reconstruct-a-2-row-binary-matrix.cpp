class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size() ;
        int sum = 0;
        int t = 0;
        for (int i=0 ; i<n ; i++) {
            sum += colsum[i];
            if (colsum[i] == 2) t++;
        }
        if (upper + lower != sum || t > min(upper , lower)) return {} ;
        vector<vector<int>> vec(2 , vector<int> (n)) ;
        for (int i=0 ; i<n ; i++) {
            if (colsum[i] == 2) {
                vec[0][i] = 1 ;
                vec[1][i] = 1 ;
                upper--;
                lower--;
            }
            else if (colsum[i] == 0) {
                vec[0][i] = 0;
                vec[1][i] = 0;
            }
            
        }
        for (int i=0 ; i<n ; i++) {
           if (colsum[i] == 1){
                if (upper > 0){
                    vec[0][i] = 1 ;
                    vec[1][i] = 0;
                    upper--;
                }
                else {
                    vec[0][i] = 0;
                    vec[1][i] = 1 ;
                    lower--;
                }
           }
        }
        return vec;
    }
};