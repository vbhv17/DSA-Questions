Approach 1: Creating a hash table of all the nodes in a linked list
bool detectLoop(Node* head)
{
    unordered_set<Node*> s;              //creating a hash table of nodes, it will contain only unique(non repeating nodes)
    while (head != NULL) {
        
        if (s.find(head) == s.end())   //s.find() will return iterator to end if node is not present in hash
        {
            s.insert(head);
            head = head->next;
        }
        else
            return true;
        
    }
 
    return false;
}

TC: O(N)  AS: O(N)


Approach 2: Floyd Cycle Finding Algorithm with slow & fast pointer
bool detectLoop(Node * head)
	{
		if (head == NULL || head->next == NULL)
			return false;
		Node *slow = head;
		Node *fast = head;
		while (fast->next && fast->next->next)
		{
			 slow = slow->next;
			 fast = fast->next->next;
			 if (slow == fast)
				 return true;
		}
		return false;
	}
  
  TC: O(N)  AS: O(1)
