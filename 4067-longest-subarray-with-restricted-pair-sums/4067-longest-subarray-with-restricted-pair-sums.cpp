class Solution {
public:
    int maxSubarray(vector<int>& a) {
        int n = a.size();
        int res = 1;
        int l = 0;
        int f[501] = {};
        f[a[l]]++;

        for(int r = 1; r < n; r++){

            bool loop = true;

            while(loop){
                loop = false;

                for(int x = 1; x < 501; x++){
                    if(!f[x]) continue;

                    int y = a[r]-x;
                    if(y > 0 && f[y]){
                        if(x != y || f[y] > 1) loop = true;
                    }

                    y = a[r] + x;
                    if(y < 501 && f[y]) loop = true;

                    if(loop) break;
                }

                if(loop) f[a[l++]]--;
            }

            f[a[r]]++;
            res = max(res, r-l+1);

        }

        return res;
    }
};