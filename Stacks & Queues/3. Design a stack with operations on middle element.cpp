/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */

We cannot use array to implement this stack because insertion and deletion operations are O(N) in array (in vector too)
We also cannot use Linked List because we have to keep track of middle pointer and in Linked List we cant move the pointer backwards
Therefore, we use doubly linked list, in which insert and delete are O(1) operations and also we can move mid ptr backward and forward according to our requirement.
  
  ********** GFG CODE (With Comments For Understanding) ****************
#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List Node */
class DLLNode {
public:
   DLLNode* prev;
   int data;
   DLLNode* next;
};

/* Representation of the stack data structure
that supports findMiddle() in O(1) time.
The Stack is implemented using Doubly Linked List.
It maintains pointer to head node, pointer to
middle node and count of nodes */
class myStack {
public:
   DLLNode* head;
   DLLNode* mid;
   int count;
};

/* Function to create the stack data structure */
myStack* createMyStack()
{
   myStack* ms = new myStack();
   ms->count = 0;
   return ms;
};

/* Function to push an element to the stack */
void push(myStack* ms, int new_data)
{
   /* allocate DLLNode and put in data */
   DLLNode* new_DLLNode = new DLLNode();
   new_DLLNode->data = new_data;

   /* Since we are adding at the beginning,
   prev is always NULL */
   new_DLLNode->prev = NULL;

   /* link the old list off the new DLLNode */
   new_DLLNode->next = ms->head;

   /* Increment count of items in stack */
   ms->count += 1;

   /* Change mid pointer in two cases
   1) Linked List is empty
   2) Number of nodes in linked list is odd */
   if (ms->count == 1) {
      ms->mid = new_DLLNode;
   }
   else {
      ms->head->prev = new_DLLNode;

      if (!(ms->count
         & 1)) // Update mid if ms->count is even
         ms->mid = ms->mid->prev;
   }

   /* move head to point to the new DLLNode */
   ms->head = new_DLLNode;
}

/* Function to pop an element from stack */
int pop(myStack* ms)
{
   /* Stack underflow */
   if (ms->count == 0) {
      cout << "Stack is empty\n";
      return -1;
   }

   DLLNode* head = ms->head;
   int item = head->data;
   ms->head = head->next;

   // If linked list doesn't
   // become empty, update prev
   // of new head as NULL
   if (ms->head != NULL)
      ms->head->prev = NULL;

   ms->count -= 1;

   // update the mid pointer when
   // we have odd number of
   // elements in the stack, i,e
   // move down the mid pointer.
   if ((ms->count) & 1)
      ms->mid = ms->mid->next;

   free(head);

   return item;
}

// Function for finding middle of the stack
int findMiddle(myStack* ms)
{
   if (ms->count == 0) {
      cout << "Stack is empty now\n";
      return -1;
   }

   return ms->mid->data;

}
// Function for deleting middle of the stack
int deleteMiddle(myStack *ms){

    if(ms->size==0){
      cout<<"Stack Underflow"
      return -1;
    }

    Node *mid = ms->middle;
    int item = mid->data;

    ms->size-=1;
   
    if(ms->size==1){
      ms->head=ms->head->next;
      ms->mid=ms->head
   }

   else if(ms->size>0){
      ms->mid->prev->next = ms->mid->next;
      ms->mid->next->prev = ms->mid->prev;

      if(ms->count & 1){
         ms->mid = ms->mid->next;
      }

      else{
         ms->mid = ms->mid->prev;
      }
   }

   delete(mid);
   return item;

}

// Driver code
int main()
{
   /* Let us create a stack using push() operation*/
   myStack* ms = createMyStack();
   push(ms, 11);
   push(ms, 22);
   push(ms, 33);
   push(ms, 44);
   push(ms, 55);
   push(ms, 66);
   push(ms, 77);

   cout << "Item popped is " << pop(ms) << endl;
   cout << "Item popped is " << pop(ms) << endl;
   cout << "Item popped is " << pop(ms) << endl;
   cout << "Middle Element is " << findMiddle(ms) << endl;
   cout << "Deleted Middle Element is "<<deletemiddle(ms)<<endl;
   cout << "Middle Element is " << findMiddle(ms) << endl;
   return 0;
}

***********************************************Code by vbhv17*****************************************************
#include<bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   Node *next;
   Node *prev;

   Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
   }
};

struct myStack{
   Node *middle;
   Node *head;
   int size;
};

void push(myStack *ms, int new_data){

   Node *new_node = new Node(new_data);
   new_node->prev = NULL;
   new_node->next = ms->head;
   ms->size+=1;

   if(ms->size==1){
      ms->middle = new_node;
   }

   else{
      ms->head->prev = new_node;

      if(!(ms->size & 1))
         ms->middle = ms->middle->prev;
   }

   ms->head = new_node;
}

int pop(myStack *ms){
  
   if(ms->size==0){
      cout<<"Stack Underflow"<<endl;
      return -1;
   }

   Node *head = ms->head;
   int item = head->data;
   ms->head = head->next;

   if(ms->head!=NULL){
      ms->head->prev = NULL;
   }

   ms->size-=1;

   if(ms->size & 1){
      ms->middle = ms->middle->next;
   }

   delete(head);

   return item;
    
}

int findMiddle(myStack *ms){
   if (ms->size == 0) {
        cout << "Stack is empty now\n";
        return -1;
    }

   return ms->middle->data;
}

int deleteMiddle(myStack *ms){

    if(ms->size==0){
      cout<<"Stack Underflow";
      return -1;
    }

    Node *mid = ms->middle;
    int item = mid->data;

    ms->size-=1;
   
    if(ms->size==1){
      ms->head=ms->head->next;
      ms->middle=ms->head;
    }

   else if(ms->size>0){
      ms->middle->prev->next = ms->middle->next;
      ms->middle->next->prev = ms->middle->prev;

      if(ms->size & 1){
         ms->middle = ms->middle->next;
      }

      else{
         ms->middle = ms->middle->prev;
      }
   }

   delete(mid);
   return item;
}


int main(){

    myStack* ms = new myStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);
 
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    cout << "Deleted Middle Element is "<<deleteMiddle(ms)<<endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    return 0;
}
