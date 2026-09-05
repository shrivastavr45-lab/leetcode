class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suf(n, 0);
        int mn = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            suf[i] = mn;
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            int ans = mx - suf[i];
            if (ans <= k) return i;
        }

        return -1;
    }
};