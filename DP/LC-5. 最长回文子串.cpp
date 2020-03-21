/**
 * 5. 最长回文子串
 */



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start(0), end(0), maxLen(0); //用来记录当前最长的回文子串
        vector <vector<bool>> dp(n, vector<bool>(n));

        for (int j = 0; j < n; j++) {
            for (int i = j; i >= 0; i--) {
                if ((s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

/**
 * 时间： O(n^2)
 * 空间：O(n^2)
 */



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        vector<bool> dp(n, false);
        //记录回文串最开始的位置，末尾位置，和最大长度
        int start(0), end(0), maxLen(0);

        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {

                dp[i] = (s[i] == s[j] && (j - i < 3 || dp[i + 1]));

                if (dp[i] && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    start = i;
                    end = j;
                }

            }
        }
        string res = s.substr(start, end - start + 1);
        return res;
    }
};
/**
 * 时间： O(n^2)
 * 空间：O(n)
 */