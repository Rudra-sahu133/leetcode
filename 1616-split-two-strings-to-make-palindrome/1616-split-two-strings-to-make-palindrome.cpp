class Solution {
public:
    bool ispal(string p) {
        int n = p.size() ;
        for (int i=0 ; i<n/2 ; i++) {
            if (p[i] != p[n-i-1]){
                return false;
            }
        }
        return true ;
    }
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        if (ispal(a)) return true;
        if (ispal(b)) return true;
        int i=0 ; 
        int j=n-1 ;
        bool f= true;
        while (i<j){
            if (a[i] == b[j]){
                i++;
                j--;
            }
            else {
                break;
            }
        }
        if (i-j == 1){
            return true ;
        }
        int l = i ; 
        int r = j;
        while (l<r){
            if (a[l] == a[r]){
                l++;
                r--;
            }
            else {
                f = false;
                break;
            }
        }
        if (f) return true ;
        f = true ;
        l = i;
        r = j;
        while (l<r){
            if (b[l] == b[r]){
                l++;
                r--;
            }
            else {
                f = false;
                break;
            }
        }
        if (f) return true ;
        i = n-1 ; j=0;
        f = true ;
        while (j<i){
            if (a[i] == b[j]){
                i--;
                j++;
            }
            else {
                
                break;
            }
        }
        if (j-i == 1) return true;
        l = j ;
        r = i;
        while (l<r) {
            if (a[l] == a[r]){
                l++;
                r--;
            }
            else {
                f = false ;
                break;

            }
        }

        if (f) return true;
        f = true;
        l = j ;
        r = i;
        while (l<r){
            if (b[l] == b[r]){
                l++;
                r--;
            }
            else {
                return false;
            }
        }
        return true ;


        // if (f) return true;

        // i=n-1 ;  j=0;
        // while (j<i){
        //     if (a[i] == b[j]){
        //         i--;
        //         j++;
        //     }
        //     else {
        //         return false;
        //     }
        // }
        // return true ;

    }
};