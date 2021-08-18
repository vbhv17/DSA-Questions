Traverse the linked list once and count the total number of 0s 1s and 2s present in the Linked List,
update this count in an array of size 3
where index 0,1 and 2 denote the count of 0s 1s and 2s in the linked list
Then traverse the list once again and fill the reqd number of 0s 1s and 2s 

PS.  This approach changes the data of nodes
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int count[3]={0,0,0};
        Node *curr=head;
        while(curr){
            count[curr->data]+=1;
            curr=curr->next;
        }
        int i=0;
        curr=head;
        
        while(curr){
            if(count[i]==0){
                i++;
            }
            
            else{
               curr->data = i;
               count[i]--;
               curr=curr->next; 
            }
        }
        return head;
    }
};


TC: O(N)
SC: O(1)
  
  Approach 2: By changing the links of nodes, we create three lists of 0s 1s and 2s and keep on adding
              nodes to it as we encounter in the original linked list
              At the end we connect 0s LL to 1s, and 1s to 2s LL
              While taking care of NULL values

Node* segregate(Node *head) {

   Node* zeroHead = NULL;
   Node* oneHead = NULL;
   Node* twoHead = NULL;
   Node* zero = NULL;
   Node* one = NULL;
   Node* two = NULL;

   Node *curr = head;
   while (curr) {

      if (curr->data == 0) {
         if (zeroHead == NULL) {
            zeroHead = curr;
            zero = curr;
         }

         else {
            zero->next = curr;
            zero = zero->next;
         }
      }

      else if (curr->data == 1) {
         if (oneHead == NULL) {
            oneHead = curr;
            one = curr;
         }

         else {
            one->next = curr;
            one = one->next;
         }
      }

      else {
         if (twoHead == NULL) {
            twoHead = curr;
            two = curr;
         }

         else {
            two->next = curr;
            two = two->next;
         }
      }

      curr = curr->next;
   }

   //Joining Lists of 0s 1s and 2s while doing NULL checks
   if (zeroHead != NULL) {
      zero->next = (oneHead) ? (oneHead) : twoHead;
   }

   if (oneHead != NULL) {
      one->next = (twoHead) ? (twoHead) : NULL;
   }

   if (twoHead != NULL) {
      two->next = NULL;
   }
   return zeroHead;
}

TC: O(N)
SC: O(1)
