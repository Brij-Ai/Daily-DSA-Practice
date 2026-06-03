#include <iostream>
#include <stack>
using namespace std;
void displayNorOrder(stack<int> &st)
{
    if (st.size() <= 0)
        return;
    int x = st.top();
    st.pop();
    displayNorOrder(st);
    cout << x << " ";
    st.push(x);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    displayNorOrder(st); // 10 20 30
    cout << st.top();
    return 0;
}