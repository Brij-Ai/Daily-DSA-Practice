#include <iostream>
#include <stack>
using namespace std;
int operation(int v1, int v2, char oper)
{
    if (oper == '+')
        return v1 + v2;
    else if (oper == '-')
        return v1 - v2;
    else if (oper == '*')
        return v1 * v2;
    else
        return v1 / v2;
}
int prio(char oper)
{
    if (oper == '+' || oper == '-')
        return 1;
    else
        return 2;
}
void kaam(char x, stack<int> &val, stack<char> &op)
{
    while (!op.empty() && prio(x) <= prio(op.top()))
    {
        char oper = op.top();
        op.pop();
        int v2 = val.top();
        val.pop();
        int v1 = val.top();
        val.pop();

        int ans = operation(v1, v2, oper);
        val.push(ans);
    }
    op.push(x);
}
int main()
{
    string exp = "2+4*6/8-17";
    stack<int> val;
    stack<char> op;

    for (char x : exp)
    {
        // check char or digit
        if (x >= 48 and x <= 57)
        {
            // digit
            val.push(x - '0');
        }
        else
        { // +,-,/,*
            if (op.empty() || prio(x) > prio(op.top()))
                op.push(x);
            else
                kaam(x, val, op);
        }
    }
    while (!op.empty())
    {
        char oper = op.top();
        op.pop();
        int v2 = val.top();
        val.pop();
        int v1 = val.top();
        val.pop();

        int ans = operation(v1, v2, oper);
        val.push(ans);
    }
    cout << val.top() << endl;
    return 0;
}