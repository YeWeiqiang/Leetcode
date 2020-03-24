/**
 * 11. 盛最多水的容器
 */


class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1;
        int res = 0;

        while(start != end)
        {
            int temp = min(height[start], height[end])*(end-start);
            res = max(temp, res);

            if(height[start] < height[end]){
                start++;
            }else{
                end--;
            }
        }

        return res;
    }
};