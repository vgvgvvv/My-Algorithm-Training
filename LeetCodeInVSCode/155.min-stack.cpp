/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (36.36%)
 * Total Accepted:    286.2K
 * Total Submissions: 786K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
#include<stack>

using namespace std;

class MinStack {
public:

    

    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        cache.push(x);
        if(!mincache.empty()){
            int lastMin = mincache.top();
            mincache.push(lastMin < x ? lastMin : x);
        }else{
            mincache.push(x);
        }
        
    }
    
    void pop() {
         if(cache.empty() || mincache.empty()){
            return;
        }
        cache.pop();
        mincache.pop();
    }
    
    int top() {
        if(cache.empty()){
            return 0;
        }
        return cache.top();
    }
    
    int getMin() {
        if(mincache.empty()){
            return 0;
        }
        return mincache.top();
    }

private:
    stack<int> cache;
    stack<int> mincache;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

