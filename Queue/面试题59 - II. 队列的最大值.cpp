/**
 * 面试题59 - II. 队列的最大值
 */


class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value() {
        if (data.empty())
            return -1;
        return max.front();
    }

    void push_back(int value) {
        data.push(value);
        while(!max.empty() && value > max.back())
            max.pop_back();
        max.push_back(value);
    }

    int pop_front() {
        if (data.empty())
            return -1;
        int val = data.front();
        if (val == max.front())
            max.pop_front();
        data.pop();
        return val;
    }
private:
    queue<int> data;
    deque<int> max;
};
