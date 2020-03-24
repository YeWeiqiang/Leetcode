/**
 * 42. 接雨水
 */


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        int maxV = 0;
        for(int i = 0; i < n; i++){
            maxV = max(maxV, height[i]);
            left[i] = maxV;
        }

        maxV = 0;
        for(int i = n-1; i >= 0; i--){
            maxV = max(maxV, height[i]);
            right[i] = maxV;
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            res += min(left[i], right[i]) - height[i];
        }

        return res;
    }
};