https://leetcode.com/problems/middle-of-the-linked-list/submissions/
https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/

Approach 1: Naive
Traverse and find the length of LL, traverse again and return the (len/2)th element
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* curr=head;
       int len=0;
        while(curr)
        {
            len++;
            curr=curr->next;
        }
        
        int mid=len/2;
        curr=head;
        while(mid)
        {
            curr=curr->next;
            mid--;
        }      
        return curr;        
    }
};


Approach 2: Using slow and fast pointers 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast!= NULL && fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
            
    }
};


Approach 3: Tricky Solution
Initialize mid element as head and initialize a counter as 0. Traverse the list from head,
while traversing increment the counter and change mid to mid->next whenever the counter is odd.
So the mid will move only half of the total length of the list. 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      int count=0;
      ListNode*  mid=head;
      while(head)
      {
          if(count%2!=0)
              mid=mid->next;
          
          count++;
          head=head->next;
      }   
      return mid;
    }
};

TC: O(N)  ~ for all 3 approches

