/**
 * 225. 用队列实现栈
 */


class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> temp_q;
        temp_q.push(x);

        while(!_data.empty()){
            temp_q.push(_data.front());
            _data.pop();
        }
        while(!temp_q.empty()){
            _data.push(temp_q.front());
            temp_q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = _data.front();
        _data.pop();

        return x;
    }

    /** Get the top element. */
    int top() {
        return _data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.empty();
    }

private:
    queue<int> _data;

};
