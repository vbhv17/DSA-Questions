#include<bits/stdc++.h> 
using namespace std;

void findMissAndRep(int arr[], int n){

   int S=0;
   int S2=0;
   S=n*(n+1)/2;
   S2=n*(n+1)*(2*n+1)/6;

   for(int i=0;i<n;i++){
      S-=arr[i];
      S2-=arr[i]*arr[i];
   }

   int x=0;
   int y=0;
   // mis-rep = S;
   // mis2 - rep2 = S2;

   y = (S2/S-S)/2;
   x = S+y;

   cout<<x<<endl<<y;
} 
int main()
{ 

   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
      cin>>arr[i];

   findMissAndRep(arr, n);
   return 0; 
}
