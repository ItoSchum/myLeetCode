#include <iostream>
#include <list>

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        _maxItr = _stackList.end();
    }
    
    void push(int x) {
        _stackList.push_back(x);
        if (_stackList.size() == 1) {
            _maxItr = _stackList.begin();
        }
    }
    
    int pop() {
        int topVal = _stackList.back();
        _stackList.pop_back();
        if (--_stackList.end() == _maxItr) {
            _maxItr = findMax();
        }
        return topVal;
    }
    
    int top() {
        return _stackList.back();
    }
    
    int peekMax() {
        _maxItr = findMax();
        return *_maxItr;
    }
    
    int popMax() {
        _maxItr = findMax();
        int maxVal = *_maxItr;
        _stackList.erase(_maxItr);
        _maxItr = findMax();
        return maxVal;
    }

private:
    std::list<int> _stackList;
    std::list<int>::iterator _maxItr;

    std::list<int>::iterator findMax() {
        std::list<int>::iterator maxItr = _stackList.begin();
        std::list<int>::iterator itr = _stackList.begin();
        for (itr = _stackList.begin(); itr != _stackList.end(); itr++) {
            if (*maxItr <= *itr) { maxItr = itr; }
        }
        return maxItr;
    }

#ifdef DEBUG
    void printStack() {
        std::list<int>::iterator itr = _stackList.begin();
        for (itr = _stackList.begin(); itr != _stackList.end(); itr++) {
            std::cout << *itr << " ";
        }
        std::cout << std::endl;
    }
#endif

};

int main() {
    MaxStack sol;
    sol.push(5);
    sol.push(1);
    sol.push(5);
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

// n = element number
// Time: push O(1), pop O(1), top O(1), peekMax O(n), popMax O(n)
// Space: O(n)