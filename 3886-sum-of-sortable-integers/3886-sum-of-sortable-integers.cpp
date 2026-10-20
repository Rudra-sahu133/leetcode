class Solution {
public:
    bool fun(vector<int>& vec, vector<int>& arr, int i, int j) {
        for (int k = i; k <= j; k++) {
            if (vec[k] != arr[k - i]) {
                return false;
            }
        }
        return true;
    }
    bool check(vector<int>& nums, int i, int j) {
        int n = nums.size();
        int cnt = 0;

        for (int k = i; k <= j; k++) {
            if (nums[k] > nums[i + (k + 1 - i) % (j - i + 1)]) {
                cnt++;
            }
        }

        return cnt <= 1;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> fc;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                fc.push_back(i);
                if (n / i != i) {
                    fc.push_back(n / i);
                }
            }
        }
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        sort(fc.begin(), fc.end());
        int ans = 0;
        for (auto it : fc) {
            int k = it;
            bool f = true;
            for (int i = 0; i < n; i += k) {
                int cnt = 0;
                vector<int> arr;
                for (int j = i; j < i + k; j++) {

                    arr.push_back(nums[j]);
                }
                sort(arr.begin() , arr.end());

                if ( !check(nums, i, i + k - 1) ||
                    !(fun(vec,arr , i, i + k - 1)) ) {
                    f = false;
                    break;
                }
            }
            if (f) {
                ans += it;
            }
        }
        return ans;
    }
}
;