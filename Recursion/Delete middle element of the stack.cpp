#include<bits/stdc++.h>
using namespace std;
void solve(stack<int> &st, int k)
{
  if(k==1)
  {
    st.pop();
    return;
  } 

  int temp = st.top();
  st.pop();

  solve(st,k - 1);

  st.push(temp);

}


void delMiddle(stack<int> &st)
{
    int n=st.size();
   int k = n/2 + 1 ;

   solve(st, k);

}

void printStack(stack<int> st)
{
   if(st.empty())
    return;

  int temp = st.top();
  st.pop();
  printStack(st);
  cout<<temp<<" ";

}

int main(){

  stack<int> st;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int data;
    cin>>data;
    st.push(data);
  }

  cout<<"Before deleting"<<endl;
  printStack(st);
  cout<<endl;
  
  delMiddle(st);

   cout<<"After deleting"<<endl;
  printStack(st);

  return 0;
}
