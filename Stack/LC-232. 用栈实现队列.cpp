/**
 * 232. 用栈实现队列
 */


class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {

        stack<int> temp_s;
        while(!_data.empty())
        {
            temp_s.push(_data.top());
            _data.pop();
        }
        temp_s.push(x);
        while(!temp_s.empty())
        {
            _data.push(temp_s.top());
            temp_s.pop();
        }

    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = _data.top();
        _data.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        return _data.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _data.empty();
    }

private:
    stack<int> _data;

};
