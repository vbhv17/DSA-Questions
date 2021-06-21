bool isCircular(Node *head)
{
   Node *curr=head;
   
   curr=curr->next;
   
   while(curr!=NULL && curr!=head)
     curr=curr->next;
     
   return(curr==head);
}

TC: O(N)
SC: O(1)
