Approach: 
# Compare first elements of both the lists, whichever is smaller make it as the head and tail both
# Keep traversing ahead in both lists compare and whichever is smaller modify the tails next to this node and then change tail to this node and move ptr to this list ahead.



Node* sortedMerge(Node* head1, Node* head2)  
{  
   if(head1==NULL)
    return head1;
    
   if(head2==NULL)
    return head2;
    
   Node *a=head1;
   Node *b=head2;
   
   Node *head=NULL;
   Node *tail=NULL;
   
   if(a->data <= b->data)
   {
       head=a;
       tail=a;
       a=a->next;
   }
   
   else
   {
       head=b;
       tail=b;
       b=b->next;
   }
   
   while(a!=NULL && b!=NULL)
   {
       if(a->data <= b->data)
       {
            tail->next=a;
            tail=a;
            a=a->next;
       }
       
       else
       {
           tail->next=b;
           tail=b;
           b=b->next;
       }
   }
   
   if(a==NULL)
      tail->next=b;
      
    else
      tail->next=a;
      
    return head;
}  
