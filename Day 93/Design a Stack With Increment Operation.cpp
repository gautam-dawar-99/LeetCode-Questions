// problem link : https://leetcode.com/problems/design-a-stack-with-increment-operation/description/
class CustomStack {
 int st[1001];
    int top, n;
public:
    CustomStack(int maxSize) {
        top = -1;
        n = maxSize;
    }
    
    void push(int x) {
        if(top + 1 == n)
            return;
        top++;
        st[top] = x;
    }
    
    int pop() {
        if(top == -1)
            return -1;

        return st[top--];
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(k, top+1); i++)
            st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */