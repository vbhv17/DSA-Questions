We have to delete nodes which have greater nodes on right,
To check for every node if it has a greater node on the right, 
we have to run two loops taking a time complexity of O(N*N)
  
Optimal Solution: Reverse the linked list and then maintain a currmax variable, curr and prev pointer
If curr nodes value is greater than or equal to currmax then no need to delete this node,
update currmax move both prev and curr one step ahead

else, If curr nodes value is smaller than currmax then curr is a node which has a greater node on the right side,
so we delete curr with the help of prev, prev points to currs next and curr points to prev next

In the end again reverse the list to get our desired output
 
class Solution
{
    public:
    
    Node *reverseList(Node *head){
        
        Node *prev=NULL;
        Node *curr=head;
        Node *next=NULL;
        
        while(curr!=NULL){
            
           next = curr->next;
           curr->next = prev;
           prev=curr;
           curr=next;
        }
        
        return prev;
    }
    
    Node *compute(Node *head)
    {
        Node *newHead = reverseList(head);
        Node* curr = newHead;
        int currmax = curr->data;
        
        Node *prev = curr;
        curr=curr->next;
            
        while(curr){
            
            if(curr->data>=currmax){
                currmax=curr->data;
                prev=curr;
                curr=curr->next;
            }
            else{
                prev->next=curr->next;
                curr=prev->next;
            }
        }
        curr = reverseList(newHead);
        return curr;
    }
};

TC: O(N)
SC: O(1)
