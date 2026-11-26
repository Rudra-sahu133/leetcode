class Solution {
public:
    bool canAliceWin(int n) {
        bool f = true;
        int cnt = 10;
        while (true) {
            if (cnt % 2 == 0) {
                if (n >= cnt) {
                    n = n - cnt;
                    cnt--;
                }
                else {
                    f = false;
                    break;
                }
            }
            else {
                if (n >= cnt){
                    n = n - cnt ;
                    cnt--;
                }
                else {
                    f= true ;
                    break;
                }
            }
        }
        return f ;
    }
};