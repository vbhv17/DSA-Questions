Approach 1: 
// Using 3 hash maps

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
  {
    unordered_map <int, int> m1, m2, m3;

    for (int i = 0; i < n1; i++)
      m1[A[i]]++;

    for (int i = 0; i < n2; i++)
      m2[B[i]]++;

    for (int i = 0; i < n3; i++)
      m3[C[i]]++;

    vector<int> res;
    for (int i = 0; i < n1; i++)
    {
      if (m1[A[i]] && m2[A[i]] && m3[A[i]] )
      { 
         res.push_back(A[i]);
         m1[A[i]] = 0;  //corner case
      }
    }
    return res;
  }

TC: O(n1+n2+n3)  AS:O(n1+n2+n3)
  
 Approach 2: Using three pointers 
//  The approach used above works well if the arrays does not contain duplicate values however it can fail in cases where the array elements are repeated. 
//    This can lead to a single common element to get printed multiple times.
// These duplicate entries can be handled without using any additional data structure by keeping the track of the previous element.
//    Since the elements inside the array are arranged in sorted manner there is no possibility for the repeated elements to occur at random positions. 
// Let’s consider the current element traversed in ar1[] be x, in ar2[] be y and in ar3[] be z and let the variables prev1, prev2, prev3 for keeping the track of
// last encountered element in each array and initialize them with INT_MIN.

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
  {
    // Initialize starting indexes
    // for A[], B[] and
    // C[]
    int i = 0, j = 0, k = 0;

    // Declare three variables prev1,
    // prev2, prev3 to track
    // previous element
    int prev1, prev2, prev3;

    // Initialize prev1, prev2,
    // prev3 with INT_MIN
    prev1 = prev2 = prev3 = INT_MIN;
    vector <int> res;

    // Iterate through three arrays
    // while all arrays have
    // elements
    while (i < n1 && j < n2 && k < n3) {

      // If A[i] = prev1 and i < n1,
      // keep incrementing i
      while (A[i] == prev1 && i < n1)
        i++;

      // If B[j] = prev2 and j < n2,
      // keep incrementing j
      while (B[j] == prev2 && j < n2)
        j++;

      // If C[k] = prev3 and k < n3,
      // keep incrementing k
      while (C[k] == prev3 && k < n3)
        k++;

      // If x = y and y = z, print
      // any of them, update
      // prev1 prev2, prev3 and move
      //ahead in each array
      if (A[i] == B[j] && B[j] == C[k]) {
        res.push_back(A[i]);
        prev1 = A[i];
        prev2 = B[j];
        prev3 = C[k];
        i++;
        j++;
        k++;
      }

      // If x < y, update prev1
      // and increment i
      else if (A[i] < B[j]) {
        prev1 = A[i];
        i++;
      }

      // If y < z, update prev2
      // and increment j
      else if (B[j] < C[k]) {
        prev2 = B[j];
        j++;
      }

      // We reach here when x > y
      // and z < y, i.e., z is
      // smallest update prev3
      // and imcrement k
      else {
        prev3 = C[k];
        k++;
      }
    }

    return res;
  }

TC: O(n1+n2+n3)  AS:O(1)
