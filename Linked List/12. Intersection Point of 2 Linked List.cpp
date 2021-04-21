Approach 1:
# Using set: Insert all nodes of first list to the set and then traverse all nodes of second list starting from the head,
# if any node of second list is already present in the set then we can say intersection of both lists starts at this node,
# return the the data of this node


Code:
int intersectPoint(Node* head1, Node* head2)
{
	unordered_set<Node*> s;
	Node* temp1=head1,*temp2=head2;
	
	while(temp1){
		s.insert(temp1);
		temp1=temp1->next;
	}
	while(temp2){
		if(s.find(temp2)==s.end()){
			temp2=temp2->next;
		}
		else{
			return temp2->data;
		}
	}
	return -1;  //not at all a Y-shaped one
}

TC: O(M+N)  AS:O(M)  //for set
  
  
  
Approach 2:  
// Get length of the first list, let it be l1.
// Get length of the second list, let it be l2.
// Get the difference of counts d = abs(l1 – l2)
// Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes 
// Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)

Code: By vbhv17
int intersectPoint(Node* head1, Node* head2)
{
    int l1=0,l2=0;
     Node *temp1=head1;
     Node *temp2=head2;

    Node *curr=head1;
    while(curr)
    {
        l1+=1;
        curr=curr->next;
    }
    
    curr=head2;
    
    while(curr)
    {
        l2+=1;
        curr=curr->next;
    }
    
    int d=abs(l1-l2);
    
    if(l1>l2)
    {
       
        while(d)
        {
            temp1=temp1->next;
            d-=1;
        }
    }
    else
    {
        
        while(d)
        {
            temp2=temp2->next;
            d-=1;
        }
        
    }
    
    while(temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
        
    }
    
    return temp1->data;
}

TC: O(M+N)  AS:O(1) 

Approach 3: Naice Trick
2-pointer technique:

// Initialize two pointers ptr1 and ptr2  at the head1 and  head2.
// Traverse through the lists,one node at a time.
// When ptr1 reaches the end of a list, then redirect it to the head2.
// similarly when ptr2 reaches the end of a list, redirect it the head1.
// Once both of them go through reassigning,hey will be equidistant from
//  the collision point
// If at any node ptr1 meets ptr2, then it is the intersection node.
// After second iteration if there is no intersection node it returns NULL.

int intersectPoint(Node* head1, Node* head2)
{
    if(head1==NULL || head2==NULL)
        return -1;
        
   Node *temp1=head1;
   Node *temp2=head2;
   
   while(temp1!=temp2)
   {
       if(temp1==NULL)
          temp1=head2;
       if(temp2==NULL)
          temp2=head1;
       
       temp1=temp1->next;
       temp2=temp2->next;
   }
   
   return temp1->data;    
}

TC: O(M+N) AS: O(1)


