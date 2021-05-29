https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#
// Solution:
// Code by vbhv17
// Using a set to store visited elements and if we encounter an element which is 
// already present in the set then it is a duplicate element, we remove it using prev pointer.
  
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates(Node *head) 
    {
        Node *prev = NULL;
        Node *curr=head;
        unordered_set<int> s;
        while(curr!=NULL)
        {
            if(s.find(curr->data) == s.end())        //if that node is not appeared before then we insert it into the set.
            {
                s.insert(curr->data);
                prev=curr;
                curr=curr->next;
            }
            else                                    //if the node is already present in the set, then curr is a duplicate node, we delete it and point to next node using prev ptr.
            {
                prev->next=curr->next;
                delete(curr);
                curr=prev->next;
            }
        }
        return head;
    }
};
TC: O(N)  SC: O(N)
