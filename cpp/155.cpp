#include <iostream>
#include <deque>

using namespace std;

class MinStack {
public:
    MinStack() :current_min(0) {}
    
    void push(int val) {
        data.push_back(val);
        if (min.empty()) {
            current_min = val;
        } else {
            if (val < current_min) {
                 current_min = val;
            }
        }
        min.push_back(current_min);
    }
    
    void pop() {
        data.pop_back();
        min.pop_back();
        if (!min.empty())
            current_min = min.back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return current_min;
    }

private:
    deque<int>  data;
    deque<int>  min;
    int current_min;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack *s = new MinStack();
    s->push(2);
    s->push(0);
    s->push(3);
    s->push(0);
    cout << s->getMin() << endl;
    s->pop();
    cout << s->getMin() << endl;
    s->pop();
    cout << s->getMin() << endl;
    s->pop();
    cout << s->getMin() << endl;
    return 0;
}
