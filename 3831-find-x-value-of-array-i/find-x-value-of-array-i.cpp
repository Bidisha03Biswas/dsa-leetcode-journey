class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);

        // dp[r] = number of subarrays ending at the previous position
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newdp(k, 0);

            // Start a new subarray with just nums[i]
            int rem = num % k;
            newdp[rem]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRem = (r * rem) % k;
                    newdp[newRem] += dp[r];
                }
            }

            // All subarrays ending here contribute to the answer
            for (int r = 0; r < k; r++) {
                result[r] += newdp[r];
            }

            dp = newdp;
        }

        return result;
    }
};