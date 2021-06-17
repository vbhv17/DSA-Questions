https://www.youtube.com/watch?v=MOGBRkkOhkY&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=7&ab_channel=AdityaVermaAdityaVerma

#include<bits/stdc++.h>
using namespace std;

void recInsert(stack<int> &s, int val)  
{
    if(s.empty() or s.top()<val)
    {
      s.push(val);
      return; 
    }
    
    int temp = s.top();
    s.pop();
    recInsert(s, val);
    s.push(temp);  
}

void recSort(stack<int> &s)            
{
     //Base Condition
     if(s.size()==1)
       return;
       
     int val = s.top();
     s.pop();
     
     recSort(s);
     
     recInsert(s, val);
}

int main(){

  int n;
  cin>>n;
  stack<int> s;
  for(int i=0;i<n;i++)
  {
     int data;
     cin>>data;
     s.push(data);
  }

  recSort(s);

  cout<<"After sorting"<<endl;
  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }

  return 0;
}
