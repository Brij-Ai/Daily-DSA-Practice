#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        next = NULL;
        this->val = val;
    }
};

class stackLL
{
public:
    Node *head;
    int size;
    stackLL()
    {
        head = NULL;
        size = 0;
    }
    void push(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << head->val << endl;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    stackLL st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();
    st.pop();
    st.display();
}