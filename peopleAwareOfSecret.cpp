#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        constexpr int mod = 1e9 + 7;
        vector<long long> dp(n, 0); // dp[i] = new people who learn the secret on day i
        dp[0] = 1; // day 1, one person knows the secret
        long long sum = 0, cnt = 0;

        for (int r = delay; r < n; r++) {
            sum += dp[r - delay] - (r >= forget ? dp[r - forget] : 0);
            dp[r] = (sum + mod) % mod;
            cnt += (r >= n - forget) ? sum : 0;
        }

        cnt += (forget == n);
        return cnt % mod;
    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 6, delay1 = 2, forget1 = 4;
    cout << "Example 1: " << sol.peopleAwareOfSecret(n1, delay1, forget1) << endl; 
    // Expected output: 5

    // Example 2
    int n2 = 4, delay2 = 1, forget2 = 3;
    cout << "Example 2: " << sol.peopleAwareOfSecret(n2, delay2, forget2) << endl; 
    // Expected output: 6

    return 0;
}
