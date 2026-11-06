class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& q) {
        int sz = logs.size();
        int len = q.size();

        vector<int> ans(len);
        vector<pair<int, int>> vec(len);
        for (int i = 0; i < q.size(); i++) {
            vec[i] = {q[i], i};
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < sz; i++) {
            swap(logs[i][0], logs[i][1]);
        }
        sort(logs.begin(), logs.end());

        int l1 = 0;
        int r1 = 0;
        map<int, int> my;

        for (int i = 0; i < q.size(); i++) {
            int a = vec[i].first - x;
            int b = vec[i].first;
            while (r1 < logs.size() && logs[r1][0] <= b) {
                
                my[logs[r1][1]]++;
                r1++;
            }
            while (l1 < logs.size() && logs[l1][0] < a) {
            
                my[logs[l1][1]]--;
                if (my[logs[l1][1]] == 0){
                    my.erase(logs[l1][1]);
                }
                l1++;
            }
            ans[(int)vec[i].second] = n - (int)my.size();
        }
        return ans;
    }
};