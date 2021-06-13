https://youtu.be/alR4VLNsqwU?t=496

Approach : We want to reverse first k elements of queue.
           1. We take first k elements out of the queue and push them into a stack
           (We have first k elements in reverse order in the stack)
           2. Then we push all elements from the stack back into the queue (In queue items are pushed at rear end )
           3. Now we take out n-k items from the queue and push them in the queue back again (we push at rear end)

queue<int> modifyQueue(queue<int> q, int k)
{
    int n=q.size();
    int k1=k;
    stack<int> st;
      
    while(k--)              //take first k elements out of the queue and push them into a stack
    {
        int front=q.front();
        q.pop();
        st.push(front);
    }
    
    while(!st.empty())    //push all elements from the stack back into the queue
    {
        q.push(st.top());
        st.pop();
    }
    
    int t=n-k1;
    
    while(t--)       //take out n-k items from the queue and push them in the queue back again
    {
        int front = q.front();
        q.pop();
        q.push(front);
    }
    
    return q;
}

TC: O(N)
SC: O(N)
