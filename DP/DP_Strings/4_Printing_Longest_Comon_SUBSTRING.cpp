#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonSubstring(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int maxLen = 0;
        int endIdx = -1; // To store the ending index of the longest common substring

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        endIdx = i - 1; // Update the ending index
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        if (maxLen == 0) {
            return ""; // No common substring found
        }

        // Extract the longest common substring from s1
        string longestCommonSubstring = s1.substr(endIdx - maxLen + 1, maxLen);
        return longestCommonSubstring;
    }
};

int main() {
    Solution obj;
    cout << obj.longestCommonSubstring("abcde", "abcd") << endl;
    return 0;
}
