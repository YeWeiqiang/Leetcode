/**
 * 347. 前 K 个高频元素
 * https://leetcode-cn.com/problems/top-k-frequent-elements/solution/qian-kge-gao-pin-yuan-su-xiao-gen-dui-by-dengmiao5/
 */

class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int, int>& a, pair<int, int>& b){ return a.second > b.second; }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> hash;
        for (auto a : nums)
        {
            hash[a]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> freq;
        for (auto a : hash)
        {
            freq.push(a);
            if (freq.size() > k)
                freq.pop();
        }
        while (!freq.empty())
        {
            res.push_back(freq.top().first);
            freq.pop();
        }
        return res;
    }

};
/**
 * 小根堆
 *
 * 时间：O(nlogn)
 * 空间：O(n)
 *
 */
