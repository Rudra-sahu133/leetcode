class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        map<int ,int>my;
        for (int i=0; i<n;i++){
            my[x[i]] = 0;
        }
        for (int i=0 ; i<n; i++){
            my[x[i]] = max(my[x[i]] , y[i]) ;
        }
        vector<int> vec;
        for (auto it : my){
            vec.push_back(it.second);
        }
        if (vec.size() < 3){
            return -1;
        }
        sort(vec.begin() , vec.end());
        int s = vec.size() ;
        return vec[s-1] + vec[s-2] + vec[s-3];

    }
};