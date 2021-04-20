Approach: Reverse the first group of size k and then recursively call for reverse function for next group.
	
struct node *reverse (struct node * head, int k)
	{
		if (head == NULL)
			return NULL;
		node *curr = head;
		node *prev = NULL;
		node *next = NULL;
		int count = 0;
		while (curr != NULL && count < k)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count += 1;
		}
		if (curr != NULL)
		{
			head->next = reverse(next, k);     //head of first group points to head of next group
		}
		return prev;                              //at last prev becomes new head of the linked list
	}
  
  TC: O(N)  AS:O(N/k)   //For each Linked List of size N, N/k or (N/k)+1 calls will be made during the recursion.
	  
	  
Approach 2: Iterative
#If k is smaller than or equal to no of nodes in ll then kth node is always going to be head of modified ll and if k is more than or equal to length of ll then after the first pass
# whatever is the last node of the ll that we processed after the first pass that is going to be the head of LL
# We run multiple passes like recursive soln but here we maintain a bool variable isFirstPass, if this firstPass is true then we set the head of the whole output ll
#and then we set isFirstPass as false so that in subsequent passes we dont modify head again.

struct node *reverse (struct node * head, int k)
  {
    if (head == NULL)
      return NULL;


    node *curr = head;
    node * prevFirst = NULL;
    bool isFirstPass = true;

    while (curr != NULL)
    {
        node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
           node *next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
           count += 1;
        }

        if (isFirstPass)
        {
          head = prev;
          isFirstPass = false;
        }
	    
        else
        {
           prevFirst->next = prev;
        }

      prevFirst = first;
    }
	
    return head;
  }

 TC: O(N)  AS:O(1) 
