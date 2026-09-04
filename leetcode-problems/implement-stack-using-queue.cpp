/*
    225. Implement Stack using Queues
    Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

    Implement the MyStack class:
        void push(int x) Pushes element x to the top of the stack.
        int pop() Removes the element on the top of the stack and returns it.
        int top() Returns the element on the top of the stack.
        boolean empty() Returns true if the stack is empty, false otherwise.
    
    Notes:
        You must use only standard operations of a queue, 
            which means that only push to back, 
            peek/pop from front, size and is empty 
            operations are valid.
        Depending on your language, the queue may not be 
            supported natively. You may simulate a queue 
            using a list or deque (double-ended queue) 
            as long as you use only a queue's standard
            operations.
    
    Example 1:
        Input
            ["MyStack", "push", "push", "top", "pop", "empty"]
            [[], [1], [2], [], [], []]
        Output
            [null, null, null, 2, 2, false]

    Explanation
        MyStack myStack = new MyStack();
        myStack.push(1);
        myStack.push(2);
        myStack.top(); // return 2
        myStack.pop(); // return 2
        myStack.empty(); // return False
    

    Constraints:
        1 <= x <= 9
        At most 100 calls will be made to push, pop, top, and empty.
        All the calls to pop and top are valid.

*/
#include <queue>
#include <iostream>
#define DEBUG(x) std::cout << #x << " = " << (x) << '\n'

using namespace std;

class MyStack {
private:
    queue<int> q;

    void rebuild(int x) {
        queue<int> tmp_q;
        while(!q.empty()) {
            tmp_q.push(this->q.front());
            this->q.pop();
        }
        this->q.push(x);
        while(!tmp_q.empty()) {
            this->q.push(tmp_q.front());
            tmp_q.pop();
        }        
    }
    
public:
    MyStack() { }
    
    void push(int x) {
        this->rebuild(x);
    }
    
    int pop() {
        int item = this->q.front();
        this->q.pop();
        return item;
    }
    
    int top() {
        return this->q.front();
    }
    
    bool empty() {
        return this->q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 int main() {
    MyStack ms = MyStack();
    
    ms.push(1);
    ms.push(2);
    ms.push(3);

    int top = ms.top();
    DEBUG(top);

    int pop = ms.pop();
    DEBUG(pop);
    
    pop = ms.pop();
    DEBUG(pop);

    pop = ms.pop();
    DEBUG(pop);

    bool emp = ms.empty();
    DEBUG(emp);
    
    return 0;
}