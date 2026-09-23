class Solution {
public:
// not my code 
        vector<int> largestPower(vector<int>& A) {
        vector<int> res(15, 0), done(15, 0);
        vector<vector<int>> groups = {A};

        for (int i = 0; i < 15; i++) {
            vector<vector<int>> groups2;
            for (auto& g : groups) {
                if (done[i]) {
                    groups2.push_back(g);
                } else {
                    vector<int> g1, g2;
                    for (int a : g) {
                        if (a & (1 << (14 - i))) g1.push_back(a);
                        else g2.push_back(a);
                    }
                    if (!g1.empty()) {
                        res[i] += g1.size();
                        groups2.push_back(g1);
                    }
                    if (!g2.empty()) {
                        done[i] = 1;
                        groups2.push_back(g2);
                    }
                }
            }
            groups = groups2;
        }
        return res;
    }
    
};