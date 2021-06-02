https://www.youtube.com/watch?v=EQQ-5FmghRw&t=712s

class Solution
{
public:

  Node * reverse(Node *head)
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

  Node* addOne(Node *head)
  {
    if (head == NULL)
      return head;

    head = reverse(head);
    Node *curr = head;

    while (curr != NULL)
    {
      if (curr->data == 9 && curr->next == NULL)
      {
        curr->data = 1;
        Node *temp = new Node(0);
        temp->next = head;
        head = temp;
        break;

      }

      else if (curr->data == 9)
      {
        curr->data = 0;
        curr = curr->next;
      }

      else
      {
        curr->data += 1;
        break;
      }
    }

    head = reverse(head);
    return head;
  }
};

TC: O(N)  SC:O(1)
