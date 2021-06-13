https://www.youtube.com/watch?v=alR4VLNsqwU&ab_channel=AdityaRajiv

void reverseQ(queue<int> &q)
{
    if(q.empty())
      return;
    
    int front = q.front();
    q.pop();
    reverseQ(q);
    q.push(front);
    
}

queue<int> rev(queue<int> q)
{
    reverseQ(q);
    return q;
}
