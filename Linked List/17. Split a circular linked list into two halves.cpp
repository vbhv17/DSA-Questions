https://www.youtube.com/watch?v=VdGIR91xlaM&ab_channel=CodeLibrary

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
  Node *slow = head;                       //Finding middle element using slow and fast ptrs
  Node *fast = head->next;
  while (fast != head and fast->next != head)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
    
   //after while loop breaks, slow will be pointing to middle element
  
  //setting head of first half
  *head1_ref = head;   
  
  //next element after middle will be head of second half 
  *head2_ref = slow->next;

  //Pointing middle element back to head
  slow->next = head;
  
  //Setting curr at head of second half
  Node *curr = *head2_ref;

  while (curr->next != head)
    curr = curr->next;

  //Making second half circular
  curr->next = *head2_ref;
}

TC: O(N)
SC: O(1)
