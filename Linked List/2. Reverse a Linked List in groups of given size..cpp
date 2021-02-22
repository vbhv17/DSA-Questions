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
			head->next = reverse(next, k);
		}
		return prev;
	}
  
  TC: O(N)  AS:O(N/k)   //For each Linked List of size N, N/k or (N/k)+1 calls will be made during the recursion.
