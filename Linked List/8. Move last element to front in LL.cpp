#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {

  int data;
  Node * next;

};

void printLL(Node * head)
{
  Node *curr = head;
  while (curr != NULL)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
}

void moveToFront(Node * head)
{
  Node *curr = head;
  Node *prev = NULL;
  while (curr->next != NULL)
  {
    prev = curr;
    curr = curr->next;
  }

  curr->next = head;
  prev->next = NULL;
  printLL(curr);

}



int main()
{
  Node *head = NULL;
  Node *second = NULL;
  Node *third = NULL;
  Node *fourth = NULL;
  Node *fifth = NULL;

  head = new Node();
  second = new Node();
  third = new Node();
  fourth = new Node();
  fifth = new Node();

  head->data = 3;
  second->data = 5;
  third->data = 7;
  fourth->data = 11;
  fifth->data = 1;

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = NULL;

  moveToFront(head);

  return 0;

}

TC:O(N)
SC: O(1)
