// Code by vbhv17
//Using 2 pointers first and second
Node *removeDuplicates(Node *head)
{
   Node *first=head;
   Node *second=head->next;
   while(second!=NULL)
   {
       if(second->data == first->data)
       {
           Node *temp = second;
           second=second->next;
           delete(temp);
           first->next=second;
       }
       
       else
       {
           first=first->next;
           second=second->next;
       }
       
   }
   return head;
}


// Another solution: Using only head without 2 pointer
// (Code Library)
 Node *removeDuplicates(Node *head)
{
   Node *hd = head;
   
   while(hd->next!=NULL)
   {
       if(hd->data == hd->next->data)
       {
           hd->next=hd->next->next;
           
       }
       else
       {
           hd=hd->next;
       }
   }
   
   return head;
}
