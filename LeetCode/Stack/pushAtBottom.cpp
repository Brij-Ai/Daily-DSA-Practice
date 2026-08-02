#include <iostream>
#include <stack>

using namespace std;
void display(stack<int> &st)
{
    if (st.size() == 0)
        return;
    int x = st.top();
    st.pop();
    cout << x << " ";
    display(st);
    st.push(x);
}
void pushAtBottom(stack<int> &st, int val)
{
    if (st.size() == 0)
    {
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottom(st, val);
    st.push(x);
}
int main()
{
    stack<int> st;
    int val = -10;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    display(st);
    pushAtBottom(st, val);
    cout << endl;
    display(st);
}