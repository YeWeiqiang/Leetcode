/**
 * 239. 滑动窗口最大值  == 面试题59 - I. 滑动窗口的最大值
 */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(k == 0) return res;
        deque <int> window;
        //找出滑动窗口的最大值
        for (int i = 0; i < k; i++) {
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        //保存首次的最大值
        res.push_back(nums[window.front()]);

        for (int i = k; i < nums.size(); i++) {
            //避免向右移动前还保留左边界的最大值，例如[1, -1], k = 1
            if (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }
            //若新插入的值比队列里的大，则抛出较小的
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
            //保存移动后的最大值，即队列头
            res.push_back(nums[window.front()]);
        }
        return res;
    }
};