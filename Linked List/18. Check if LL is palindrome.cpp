https://www.youtube.com/watch?v=-DtNInqFUXs&ab_channel=takeUforward

Naive Approach:
Copy all elements of the linked list to a vector and then iterate linked list from starting and vector from back,
compare both the elements, If they are not equal return -1
  
  
 bool isPalindrome(Node *head)
{

    if (head == NULL or head->next == NULL)
        return true;

    vector<int> rev;
    Node *curr = head;
    while (curr != NULL) {
        rev.push_back(curr->data);
        curr = curr->next;
    }

    int i = v.size() - 1;

    curr = head;
    while (curr != NULL) {
        if (curr->data != rev[i]) {
            return false;
        }

        i--;
        curr = curr->next;
    }

    return true;
}

TC: O(N)
SC: O(N)
  
  
Efficient Approach: Find out midddle element of linked list and reverse the whole linked list after middle element (second half of linked list)
                    Iterate elements of first half and second half one by one if they are not equal return -1
                      
class Solution {
public:
    //Function to check whether the list is palindrome.

    Node *reverseList(Node *head) {

        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL) {

            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL and fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);

        slow = slow->next;
        Node *curr = head;

        while (slow != NULL) {
            if (curr->data != slow->data) {
                return false;
            }

            slow = slow->next;
            curr = curr->next;
        }

        return true;
    }
};

TC: O(N)
SC: O(1)
