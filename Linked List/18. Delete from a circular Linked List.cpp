Three case:
If node to be deleted is head node
If node to be deleted is last node 
If node to be deleted is any middle node 

void deleteNode(Node** head, int key)
{

   Node *curr = *head;
   Node *prev = *head;

   while (curr) {
      if (curr->data == key) {
         break;
      }

      prev = curr;
      curr = curr->next;
   }

   if (curr == NULL)
      cout << "No such node with key value found";

   //If node to be deleted is head node (curr pointing to head)
   if (curr == *head) {
      while (prev->next != *head)
         prev = prev->next;

      prev->next = curr->next;
      delete(curr);
   }

   //If node to be deleted is last node of circular LL
   else if (curr->next == *head) {
      prev->next = curr->next->next;
      delete(curr);
   }

   //if node to be deleted is any middle node
   else {
      prev->next = curr->next;
      delete(curr);
   }

}

TC :O(N)
SC :O(1)
