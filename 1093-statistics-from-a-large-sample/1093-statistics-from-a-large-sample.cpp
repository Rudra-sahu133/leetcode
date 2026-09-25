class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size() ;
        double mx = -1;
        double mn= 1000;
        double sum = 0;
        double md = -1;
        long long tt = 0 ;
        int len = 0;
        int c = -1;
        for (int i=0 ; i<n ; i++) {
            if (count[i] > 0) {
                mx= max(mx , i + 0.0);
                mn = min(mn , i + 0.0);
                sum += ((double)(i)*(double(count[i])));
                if (c <= count[i]){
                    c = count[i];
                    md = i;
                }
                tt += count[i];
                len += count[i];
            }

        }
        double mwd = 0 ;

        if (tt % 2 != 0){
            double f = -1;
            tt = (tt + 1 ) / 2 ;
            for (int i=0 ; i<n ; i++) {
                if (count[i] > 0){
                    if (tt > count[i]) {
                        tt = tt - count[i];
                    }
                    else{
                        f = i;
                        break;
                    }
                }
                
            }
            mwd = f ;
        }
        else{
            int r1 = tt / 2 ;
            int r2 = r1+1 ;
            double f1 = -1;
            double f2 = -1;
            for (int i=0 ; i<n ; i++) {
                if (count[i] > 0){
                    if (r1 > count[i]) {
                        r1 = r1 - count[i];
                    }
                    else{
                        f1 = i;
                        break;
                    }
                }
                
            }
            for (int i=0 ; i<n ; i++) {
                if (count[i] > 0){
                    if (r2 > count[i]) {
                        r2 = r2 - count[i];
                    }
                    else{
                        f2 = i;
                        break;
                    }
                }
                
            }
            mwd = (f1 + f2 ) / (2.0) ;
        }

        return  {mn , mx , sum / len , mwd , md} ;

    }
};