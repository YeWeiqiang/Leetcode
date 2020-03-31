/**
 * 155. 最小栈
 */


class MinStack {
private:
    stack<int> s;
    int min = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(x <= min){
            s.push(min); //在每一个min入栈之前将它前一个min入栈
            min = x;
        }
        s.push(x);
    }

    void pop() {
        int temp = s.top();
        s.pop();
        //如果取出来的是当前min，就将压在它低下的前一个min出栈
        //因为前一个min是维持之前的最小栈，需要还原之前的min状态并且出栈
        if(temp == min){
            min = s.top();
            s.pop();
        }

    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min;
    }
};
