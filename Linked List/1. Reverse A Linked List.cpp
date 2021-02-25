*Refer Notes*
Approach 1: Create an auxillary array and copy all elements of LL to it and then copy again to LL in reverse order
TC:O(N)  AS:O(N)   //requires two traversals and auxillary space

Approach 2: Maintain prev curr and next pointers

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }

    return prev;      //prev becomes new head
}
TC:O(N)  AS:O(1)
  
  
  Approach 3: Recursive Reverse  //Tail Recursive
    Node *recReverse(Node *curr, Node *prev)
{
    if (curr == NULL)
        return prev;

    Node *next = curr->next;
    curr->next = prev;
    return recReverse(next, curr);

}

int main()
{
    recReverse(head, NULL);
}
TC:O(N)  AS:O(N)
  
  Approach 4: Recursive Method 2 (Not a tail recursive method)
    //The idea is to to reverse the rest of the linked list except head using recusrion and then adding head to the tail of the reversed LL 
    Node* recRevLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest_head = recRevLL(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}
TC:O(N)  AS:O(N)
  
  Approach 5: Using Stack
  
  class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
    stack<int> st;
    ListNode *curr=head;
    while(curr)
    {
        st.push(curr->val);
        curr=curr->next;
    }
    
    curr=head;
    while(curr)
    {
        int data=st.top();
        curr->val=data;
        st.pop();
        curr=curr->next;
    }
    
    return head;
}
};

  TC:O(N)  AS:O(N)

  

