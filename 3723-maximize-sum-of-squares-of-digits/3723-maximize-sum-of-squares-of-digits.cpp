class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9*num){
            return "" ;
        }
        string p = "" ;
        int n = num ;
        while (n) {
            p += '9';
            n--;
        }
        int s = 9*num ;
        int i= num-1 ;
        while ( i >=0 && s > sum){
            if (s - sum > 9){
                p[i] = '0';
                i--;
                s = s - 9 ;
            }
            else {
                p[i] = char('0' + (9 - (s-sum))) ;
                break;
            }
        }
        return p ;
    }
};