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
