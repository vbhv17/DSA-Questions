Naive Pattern Matching Algorithm:
https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void search(char pat[], char txt[])
{
    int n=strlen(txt);
    int m=strlen(pat);

    for(int i=0; i<=n-m; i++)
    {
      int j;
       for(j=0;j<m;j++)
       {
          if(pat[j]!=txt[i+j])
            break;
       }

       if(j==m)
        cout<<"Pattern found at index"<<": "<<i<<endl;
    }
}

int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    search(pat, txt);
    return 0;
}


The Naive String Matching algorithm slides the pattern one by one. After each slide, 
it one by one checks characters at the current shift and if all characters match then prints the match. 
Like the Naive Algorithm, Rabin-Karp algorithm also slides the pattern one by one.
   But unlike the Naive algorithm, Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text,
and if the hash values match then only it starts matching individual characters. So Rabin Karp algorithm needs to calculate hash values for following strings.
1) Pattern itself. 
2) All the substrings of the text of length m. 
  
 How is rolling hash calculated?
  https://www.youtube.com/watch?v=BQ9E-2umSWc

Refer Notes & GFG Article for concept and code   https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

Code:
/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
	txt -> text
	q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++)
	{

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters on by one
		if ( p == t )
		{
			/* Check for characters one by one */
			for (j = 0; j < M; j++)
			{
				if (txt[i+j] != pat[j])
					break;
			}

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
			if (j == M)
				cout<<"Pattern found at index "<< i<<endl;
		}

		// Calculate hash value for next window of text: Remove
		// leading digit, add trailing digit
		if ( i < N-M )
		{
			t = (d*(t - txt[i]*h) + txt[i+M])%q;

			// We might get negative value of t, converting it
			// to positive
			if (t < 0)
			t = (t + q);
		}
	}
}

/* Driver code */
int main()
{
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEK";
	
	// A prime number
	int q = 101;
	
	// Function Call
	search(pat, txt, q);
	return 0;
}

TC: O(n*m) ~ Worst Case
    O(n+m) ~ Best Case
  
