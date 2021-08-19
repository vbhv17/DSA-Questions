Naive Solution: Using three nested loops generate all triplets and check whether elements in the triplet sum up to x or not.
  int countTriplets(struct Node* head, int x)
{
   struct Node* ptr1, *ptr2, *ptr3;
   int count = 0;

   // generate all possible triplets
   for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
      for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
         for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)

            // if elements in the current triplet sum up to 'x'
            if ((ptr1->data + ptr2->data + ptr3->data) == x)

               // increment count
               count++;

   // required count of triplets
   return count;
}

Better Solution: Using extra space (set)
  
int countTriplets(struct Node* head, int x)
{
   // if list is empty
   if (head == NULL)
      return 0;

   int count = 0;

   unordered_set<int> st;

   for (Node *one = head; one->next->next->next != NULL; one = one->next) {

      int rem = x - one->data;
      Node *two = one->next;
      while (two) {
         int trem = rem - two->data; //total remaining
         if (st.find(trem) != st.end()) {
            count++;
         }

         else {
            st.insert(two->data);
         }

         two = two->next;
      }

      st.clear();

   }

   return count;
}
TC: O(N*N)
SC: O(N)

Optimal Approach: Fix one pointer and then find two other pairs using two pointer method

int countTriplets(struct Node* head, int x)
{
   // if list is empty
   if (head == NULL)
      return 0;

   int count = 0;
   Node *first = head;
   Node *last = head;
   while (last->next != NULL)
      last = last->next;


   for (Node *one = head; one->next->next->next != NULL; one = one->next) {

      Node *left = one->next;
      Node *right = last;

      while (left != right && left->next != right) {

         int sum = one->data + left->data + right->data;

         if (sum == x) {
            count++;
            left = left->next;
            right = right->prev;
         }

         else if (sum > x) {
            right = right->prev;
         }

         else {
            left = left->next;
         }
      }
   }

   return count;
}

TC: O(N*N)
SC: O(1)
