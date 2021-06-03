Node* findIntersection(Node* head1, Node* head2)
{
  Node *first = head1;
  Node *second = head2;
  Node *res = NULL;
  Node *curr = NULL;
  Node *temp;
  while (first != NULL && second != NULL)
  {
    if (first->data < second->data) {

      first = first->next;
    }

    else if (first->data > second->data) {

      second = second->next;
    }

    else {

      Node *temp = new Node(first->data);

      if (res == NULL) {

        res = temp;
        curr = temp;
      }

      else {

        curr->next = temp;
        curr = temp;
      }

      if (first) first = first->next;
      if (second) second = second->next;
    }

  }

  return res;
}
