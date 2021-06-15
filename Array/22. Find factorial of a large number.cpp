Since factorial of big numbers can result in a huge number, which can have 100's of trailing digits, 
Size of int is 10^9 (maximum 10 digits)
Size of long long int is 10^18 (maximum 19 digits)
  
Therefore, we use a linked list to store individual digits of the factorial, 
We start with tail of linked list since we start multiplying from the right most digit (imagine basic maths multiplication)

https://www.youtube.com/watch?v=VCfZOe1oJHU&t=503s&ab_channel=DhruvGoyal

//code by vbh17
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *prev;

  Node(int x)
  {
    data = x;
    prev = NULL;
  }
};

void factorial(Node *tail, int n)
{

  //initializing curr and prevNode as tail since we have to start multiplying from the right side
  //as we do in maths, we multiply the rightmost digit first
  Node *curr = tail;
  Node *prevNode = tail;

  int carry = 0;
  while (curr != NULL)
  {
    //data is result of multiplication of n and curr->data
    int data = (((curr->data) * n ) + carry);

    //from data, data%10 will be new curr data and data/10 will give the carry
    curr->data = data % 10;
    carry = data / 10;

    //updating prev and curr nodes
    prevNode = curr;
    curr = curr->prev;
  }


  //if curr becomes null and carry is not zero we have to make new nodes
  while (carry != 0)
  {
    prevNode->prev = new Node((int)(carry % 10));
    carry = carry / 10;
    prevNode = prevNode->prev;
  }
}

void printList(Node *tail)
{
  if (tail == NULL)
    return;
  printList(tail->prev);
  cout << tail->data;
}

int main()
{

  int n;
  cin >> n;

  Node *tail = new Node(1);

  for (int i = 2; i <= n; i++)
    factorial(tail, i);

  printList(tail);

}
