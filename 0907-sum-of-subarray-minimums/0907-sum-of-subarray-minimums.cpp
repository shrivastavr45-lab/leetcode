class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        int mod = 1e9 + 7;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int index = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long count = 1LL * (index - left) * (right - index);
                sum = (sum + count * arr[index]) % mod;
            }

            st.push(i);
        }

        return sum;
    }
};