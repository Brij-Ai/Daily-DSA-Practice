#include <iostream>
#include <stack>
using namespace std;
void reverseStack(stack<int> &s)
{
    stack<int> stackA;
    stack<int> stackB;
    while (s.size() > 0)
    {
        stackA.push(s.top());
        s.pop();
    }
    while (stackA.size() > 0)
    {
        stackB.push(stackA.top());
        stackA.pop();
    }
    while (stackB.size())
    {
        s.push(stackB.top());
        stackB.pop();
    }
}
int main()
{
    stack<int> stack_;
    stack_.push(10);
    stack_.push(20);
    stack_.push(30);
    stack_.push(40);
    stack_.push(50);
    cout << stack_.top() << endl;
    reverseStack(stack_);
    cout << stack_.top();
    return 0;
}