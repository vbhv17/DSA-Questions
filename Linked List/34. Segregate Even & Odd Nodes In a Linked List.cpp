Approach 1: (Coded by vbhv17)
# The idea is to get pointer to the last node of list.
# And then traverse the list starting from the head node and move the odd valued nodes from their current position to end of the list.

// Algorithm:
// …1) Get pointer to the last node.
// …2) Move all the odd nodes to the end.
// ……..a) Consider all odd nodes before the first even node and move them to end.
// ……..b) Change the head pointer to point to the first even node.
// ……..b) Consider all odd nodes after the first even node and move them to the end.

Code : (By vbhv17)   //giving some error on gfg
class Solution{
public:
    Node* divide(int N, Node *head){
        
      Node *curr=head;
      Node *newHead;
      int flag=0;
      
      while(curr->next)
      {
          if(curr->data%2==0 && flag==0)
          {
              Node *newHead=curr;
              flag=1;
          }
          curr=curr->next;
      }
      
      Node *last=curr;
      curr=head;
      
      while(curr->next)
      {
          Node *temp=curr;
         if(temp->data%2!=0)
         {
             curr=curr->next;
             last->next=temp;
             temp->next=NULL;
             last=temp;
         }
         
         else
         curr=curr->next;
         
      }
      return newHead;
    }
};

TC: O(N) Two Traversals AS: O(1)
  
  
Approach 2:
// The idea is to split the linked list into two: one containing all even nodes and other containing all odd nodes. And finally attach the odd node linked list after the even 
// node linked list.
// To split the Linked List, traverse the original Linked List and move all odd nodes to a separate Linked List of all odd nodes.
// At the end of loop, the original list will have all the even nodes and the odd node list will have all the odd nodes. 
// To keep the ordering of all nodes same, we must insert all the odd nodes at the end of the odd node list. And to do that in constant time,
// we must keep track of last pointer in the odd node list.

Code :
Node* divide(int N, Node *head){
     
        Node *es=NULL;
        Node *ee=NULL;
        Node *os=NULL;
        Node *oe=NULL;
        
        for(Node *curr=head ; curr!=NULL; curr=curr->next)
        {
            int x = curr->data;
            if(x % 2 == 0)
            {
                if(es==NULL)
                {
                    es=curr;
                    ee=es;
                }
                
                else
                {
                    ee->next=curr;
                    ee=ee->next;
                }
            }
            
            else
            {
                if(os==NULL)
                {
                    os=curr;
                    oe=os;
                }
                
                else
                {
                    oe->next=curr;
                    oe=oe->next;
                }
            }
        }
        
        if(os==NULL || es==NULL)
           return head;
           
        ee->next=os;
        oe->next=NULL;
        
        return es;
        
    }

TC: O(N)- One Traversal AS:O(1)

