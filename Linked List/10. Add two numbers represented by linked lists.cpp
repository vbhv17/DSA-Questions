https://www.youtube.com/watch?v=EvjpRN9CpDI&t=212s

class Solution
{
public:
  //Function to add two numbers represented by linked list.

  struct Node * reverse(Node *head)
  {
    if (head == NULL)
      return head;

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
      Node *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }


  struct Node* addTwoLists(struct Node* first, struct Node* second)
  {
    first = reverse(first);
    second = reverse(second);
    int c = 0, s = 0;

    Node *temp;
    Node *res = NULL;
    Node *curr = NULL;

    while (first != NULL || second != NULL)
    {
      s = c + (first ? first->data : 0) + (second ? second->data : 0);
      c = (s > 9 ? 1 : 0);
      s = s % 10;

      Node *temp = new Node(s);
      if (res == NULL) {             //if the res LL is empty (initially)

        res = temp;
        curr = temp;
      }

      else {                       //if res LL already has some nodes (not empty)
        curr->next = temp;
        curr = temp;
      }

      if (first) first = first->next;       //so that we dont access NULL->next (segmentation fault)
      if (second) second = second->next;
    }

    if (c > 0) {                  //for the case (90+10) where one digit is increased          
      temp = new Node (c);                  
      curr->next = temp;
      curr = temp;
    }

    res = reverse(res);
    return res;
  }
};
