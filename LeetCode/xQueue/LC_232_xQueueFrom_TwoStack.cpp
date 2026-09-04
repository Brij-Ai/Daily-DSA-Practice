#include <stack>
using namespace std;
class MyQueue
{
public:
    stack<int> front, rear;
    MyQueue()
    {
    }

    void push(int x)
    {
        rear.push(x);
    }

    int pop()
    {
        if (rear.empty())
            return -1;
        while (!rear.empty())
        {
            front.push(rear.top());
            rear.pop();
        }
        int popped = front.top();
        front.pop();
        while (!front.empty())
        {
            rear.push(front.top());
            front.pop();
        }
        return popped;
    }

    int peek()
    {
        if (rear.empty())
            return -1;
        while (!rear.empty())
        {
            front.push(rear.top());
            rear.pop();
        }
        int popped = front.top();
        while (!front.empty())
        {
            rear.push(front.top());
            front.pop();
        }
        return popped;
    }

    bool empty()
    {
        if (rear.empty())
            return true;
        return false;
    }
};

int main()
{

    // Your MyQueue object will be instantiated and called as such:
    MyQueue *obj = new MyQueue();
    int x = 10;
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
}