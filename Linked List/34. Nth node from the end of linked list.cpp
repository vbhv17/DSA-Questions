Approach 1: Traverse once and find length of linked list and then return (length-n+1)th element from starting
int getNthFromLast(Node *head, int n)
{
    
    if(head==NULL)
      return -1;
      
    int length=0;
    
    Node *curr=head;
    
    while(curr){
        length++;
        curr=curr->next;
    }
    
    if(n>length) return -1;
    
    int targetnode = length-n+1;
    
    curr=head;
    while(--targetnode && curr!=NULL){
        curr=curr->next;
    }
    
    if(curr==NULL)  return -1;
    
    return curr->data;

}

Approach 2: Use slow and fast pointers
Move fast pointer n-1 steps ahead initially and then move both ptrs one by one until fast->next doesnt become NULL
 Return slow->data when fast->next becomes NULL
  
  int getNthFromLast(Node *head, int n)
{
    //finding length and checking if n>l
    
    if(head==NULL) return -1;
    
    int length=0;
    
    Node *curr=head;
    
    while(curr){
        length++;
        curr=curr->next;
    }
    
    if(n>length) return -1;
    
    //Using slow and fast ptrs
  
    Node *slow=head;
    Node *fast=head;
    
    int p=1;
    while(p<=n-1){
        fast=fast->next;
        p++;
    }
    
    while(fast != NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    
    return slow->data;
}

TC: O(N)
SC: O(1)
