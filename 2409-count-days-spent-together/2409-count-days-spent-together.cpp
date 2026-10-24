class Solution {
public:
    int fun (string s , vector<int> &mon){
        return mon[(s[0] - '0')*10 + (s[1] - '0') - 1] + (s[3]-'0')*10 + (s[4] - '0') ;
    }
    int countDaysTogether(string ara, string laa, string arb, string lbb) {
        vector<int> mon = {0 , 31,28,31,30,31,30,31,31,30,31,30,31} ;
        for(int i=1 ; i<= 12 ; i++) {
            mon[i] = mon[i] + mon[i-1] ;
        }
        int aa = fun (ara , mon) ;
        int la = fun (laa , mon) ;
        int ab = fun (arb , mon) ;
        int lb = fun (lbb , mon) ;

        vector<vector<int>> vec(2 , vector<int> (2));
        vec[0][0] = aa ;
        vec[0][1] = la ;
        vec[1][0] = ab ;
        vec[1][1] = lb ;
        sort(vec.begin() , vec.end()) ;
        if (vec[1][0] <= vec[0][1]){
            int l = max(vec[0][0] , vec[1][0]);
            int r = min(vec[0][1] , vec[1][1]) ;
            return r - l+ 1;
        }
        return  0;



    }
};