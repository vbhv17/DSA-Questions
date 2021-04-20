# Approach: First detect a loop using floyd cycle detection algorithm if a loop is found, move slow to head and then move slow and fast one position ahead until slow->next 
# becomes equal to fast->next. At this time fast will be pointing to the last node of the linked list, So set fast->next=NULL

void removeLoop(Node* head)
    {
        Node *slow=head, *fast=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(fast==slow)
              break;
        }
        
        if(slow!=fast)
          return ;
          
        slow=head;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        fast->next=NULL;

    }

TC: O(N)    AS: O(1)
