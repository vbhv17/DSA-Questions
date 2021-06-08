Node* reverseDLL(Node * head)
{
    if(head==NULL || head->next==NULL)
      return head;
      
    Node *curr=head;
    
    while(curr->next!=NULL)
      curr=curr->next;
     
    head=curr;
    
    while(curr!=NULL)
    {
        Node *temp = curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->next;
    }
    
    return head;
}

TC: O(N) ~ two traversals
SC: O(1)
