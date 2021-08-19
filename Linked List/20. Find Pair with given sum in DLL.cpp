A simple approach for this problem is to one by one pick each node and find a second element whose sum is equal to x
in the remaining list by traversing in the forward direction. The time complexity for this problem will be O(n^2),
n is the total number of nodes in the doubly linked list.

An efficient solution for this problem is the same as this article. Here is the algorithm :  
Initialize two pointer variables to find the candidate elements in the sorted doubly linked list. 
  Initialize left with the start of the doubly linked list i.e; left=head and initialize right with the last node of the doubly linked list i.e; right=last_node.
We initialize left and right pointers as first and last nodes. Here we don’t have random access, so to find the right pointer, we traverse the list to initialize the right.
If current sum of left and right is less than x, then we move left in forward direction. If current sum of left and right element is greater than x,
then we move right in backward direction.
Loop termination conditions are also different from arrays. The loop terminates when two pointers cross each other (second->next = first), 
or they become the same (first == second).
The case when no pairs are present will be handled by the condition “first==second”

void pairSum(struct Node *head, int x)
{
	if(!head){
     cout<<"Empty Linked List";
    return;
  }
  
  Node *left=head;
  Node *right = head;
  while(right->next!=NULL)
    right=right->next;
  bool flag = false;
  while(left!=right){
     int sum = left->data + right->data;
    
    if(sum==x){
      flag=true;
        cout<<"("<<left->data<<","<<right->data<<")"<<endl; 
        left=left->next;
        right=right->prev;
    }
    
    else if(sum<x)
      left=left->next;
    
    else
      right=right->prev;
    
  }
  if(!flag){
     cout<<"No Pair Found"<<endl;
  }
  return;
}

TC: O(N)
SC: O(1)
