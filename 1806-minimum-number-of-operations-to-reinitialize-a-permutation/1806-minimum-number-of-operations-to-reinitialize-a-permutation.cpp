class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int>next(n);
        if(n==2){return 1;}
        for(int i=1;i<n/2;i++){
            next[i]=2*i;
            next[n/2-1+i]=2*i-1;
        }
        int ans=0;
        int present=1;
        while(1){
            present=next[present];
            ans++;
            if(present==1){break;}
        }
        return ans;
    }
};