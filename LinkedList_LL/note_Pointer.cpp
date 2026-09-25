#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        val = 0;
        next = NULL;
    }

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void display(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayRec(Node *head)
{
    if (head == NULL)
        return;
    cout << head->val << " ";
    display(head->next);
}
int main()
{

    return 0;
}