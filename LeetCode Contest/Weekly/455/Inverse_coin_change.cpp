/*
    Q2. Inverse Coin Change
    Medium
    5 pt.
    You are given a 1-indexed integer array numWays, where numWays[i] represents the number of ways to select a total amount i using an infinite supply of some fixed coin denominations. Each denomination is a positive integer with value at most numWays.length.

    However, the exact coin denominations have been lost. Your task is to recover the set of denominations that could have resulted in the given numWays array.

    Return a sorted array containing unique integers which represents this set of denominations.

    If no such set exists, return an empty array.

    Constraints:
        1 <= numWays.length <= 100
        0 <= numWays[i] <= 2 * 10^8
    
    Example 1:
    Input: numWays = [0,1,0,2,0,3,0,4,0,5]
    Output: [2,4,6]

    Example 2:
    Input: numWays = [1,2,2,3,4]
    Output: [1,2,5]
*/
#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> findCoins(std::vector<int>& numWays) {
        int n = numWays.size();
        std::vector<long long> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = numWays[i];
        }
        dp[0] = 1;

        std::vector<int> coins;

        if (dp[0] != 1) {
            return {};
        }

        for (int c = 1; c <= n; ++c) {
            if (dp[c] < 0) {
                return {};
            }

            if (dp[c] > 0) {
                coins.push_back(c);
                for (int i = c; i <= n; ++i) {
                    dp[i] -= dp[i - c];
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (dp[i] != 0) {
                return {};
            }
        }

        return coins;
    }
};