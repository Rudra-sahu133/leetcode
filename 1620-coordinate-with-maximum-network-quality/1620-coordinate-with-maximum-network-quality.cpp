class Solution {
public:
    double fun (int x1 , int y1 , int x2 , int y2){
    //  return abs(x2-x1) + abs(y2-y1);
        double p  = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        return sqrt(p);
    }
    vector<int> bestCoordinate(vector<vector<int>>& t, int r1) {
        int n =  t.size() ;
        int ans = 0;
        int l = INT_MAX; 
        int r = INT_MAX;
        for(int x =0 ;x<=100 ; x++) {
            for (int y=0 ; y<=100 ; y++) {
                int mx = 0;
                for (int i=0 ; i<n ; i++) {
                    double d = fun (x , y ,t[i][0] , t[i][1] );
                    if (d <= r1){
                        mx += floor((t[i][2] / (1+d))) ;
                    }
                }

                if (mx > ans){
                    ans = mx ;
                    l=x ;
                    r = y ;
                }
                else if (ans == mx){
                    if (x < l){
                        l = x ;
                        r = y ;
                    }
                    else if (x == l){
                        if(y < r){
                            r = y ;
                            l = x ;
                        }
                    }
                }
            }
        }

        return {l , r};
    }
};