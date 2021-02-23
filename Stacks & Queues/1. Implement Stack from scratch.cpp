Stacks can be implemented either using array or using Linked List

Array Implementation:
/* C++ program to implement basic stack
   operations */
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000
 
class Stack {
    int top;
 
public:
    int a[MAX]; // Maximum size of Stack
 
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
 
bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}
 
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
 
bool Stack::isEmpty()
{
    return (top < 0);
}
 
// Driver program to test above functions
int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
 
    return 0;
}




Linked List Implementation:
// C++ program for linked list implementation of stack
#include <bits/stdc++.h>
using namespace std;
 
// A structure to represent a stack
class StackNode {
public:
    int data;
    StackNode* next;
};
 
StackNode* newNode(int data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(StackNode* head)
{
    return !head;
}
 
void push(StackNode** head, int data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *head;
    *head = stackNode;
    cout << data << " pushed to stack\n";
}
 
int pop(StackNode** head)
{
    if (isEmpty(*head))
        return INT_MIN;
    StackNode* temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    free(temp);
 
    return popped;
}
 
int peek(StackNode* head)
{
    if (isEmpty(head))
        return INT_MIN;
    return head->data;
}
 
// Driver code
int main()
{
    StackNode* head = NULL;
 
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
 
    cout << pop(&head) << " popped from stack\n";
 
    cout << "Top element is " << peek(head) << endl;
 
    return 0;
}
