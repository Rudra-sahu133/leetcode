class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy){
            if (t == 1) return false;
             else return true;
            
        }
        if (sx == fx){
            int dt = abs(sy-fy);
            if (dt > t) return false;
            return true;
        }
        if (fy == sy){
            int dt = abs(sx-fx);
            if (dt > t) return false;
            return true;
        }
        int mn = min(abs(sx - fx) ,  abs(sy-fy));
        int st = abs(sx - fx) - mn + abs(sy-fy) ;
        if (mn == 0){
            if (t ==  0) return true;
            else return false;

        }
        if (t < st) {
            return false;
        }
        else if (t == st) return true ;

        else if (t >= st && t <= abs(sx - fx) + abs(sy-fy)) return  true; 

        
        else  {
            if ( t - ((abs(sx - fx) + abs(sy-fy))) % 2 == 0){
                return true ;
            }
            else if ( (t- st ) % 2 == 0) return true ;
            
            else return true ;
        }
    }
};