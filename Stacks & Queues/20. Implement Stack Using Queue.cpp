# We use 2 queues, q1 and q2, of which q2 is auxillary queue used for pushing elements to the front of the queue q1 (As in queue items are inserted from the back)
/* Program to implement a stack using 
two queue */
#include <bits/stdc++.h>

using namespace std;

class Stack {
    // Two inbuilt queues
    queue<int> q1, q2;

    // To maintain current number of
    // elements
    int curr_size;

public:
    Stack()
    {
        curr_size = 0;
    }

    void push(int x)
    {
        curr_size++;

//         Push all elements of q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
      
//      Push element x in q1
        q1.push(x);

//      Add elements back to q1 from q2
        while(!q2.empty())
        {
          q1.push(q2.front())
            q2.pop();
        }
    }

    void pop()
    {

        // if no elements are there in q1
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size()
    {
        return curr_size;
    }
};

// Driver code
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size()
         << endl;
    return 0;
}
// This code is contributed by Chhavi
