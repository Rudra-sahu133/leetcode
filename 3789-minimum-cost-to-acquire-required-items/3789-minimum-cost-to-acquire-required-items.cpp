class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long mn = min(cost1 + cost2 + 0LL, 0LL + costBoth ) ;
        long long ans = 0;
        if (need1 <= need2) {
            ans += mn*(need1*1LL)*1LL ;
            need2 = need2 - need1 ;
            ans += min(cost2 + 0LL ,0LL +  costBoth)*(need2*1LL)*1LL;
        }
        else {
            ans += mn*(need2*1LL)*1LL ;
            need1 = need1 - need2 ;
            ans += min(cost1 +0LL, 0LL+ costBoth)*(need1*1LL)*1LL;
        }
        return ans;
    }
};