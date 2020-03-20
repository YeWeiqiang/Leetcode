
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start(0), end(0), length(0), res(0);
        unordered_map<char, int> hash;

        while(end < s.length())
        {
            char tempChar = s[end];
            if(hash.find(tempChar) != hash.end() && hash[tempChar] >= start){
                start = hash[tempChar] + 1;
                length = end - start;
            }
            hash[tempChar] = end;

            end++;
            length++;
            res = max(res, length);
        }

        return res;
    }
};


/**
 *
 * 时间：O(n)
 * 空间：O(n)
 *
 */