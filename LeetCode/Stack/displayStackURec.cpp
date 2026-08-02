#include <iostream>
#include <stack>
using namespace std;
void displayRev(stack<int> &st)
{
    if (st.size() <= 0)
        return;
    int x = st.top();
    cout << x << " ";
    st.pop();
    displayRev(st);
    st.push(x);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    displayRev(st);
    cout << st.top();
    return 0;
}