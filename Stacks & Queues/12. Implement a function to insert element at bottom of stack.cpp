// Implement a method to insert an element at its bottom without using any other data structure. Solution
#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x){
    
    if(st.size()==0){
      st.push(x);
      return;
    }
    
    int temp = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(temp);
    
}

int main(){
    
    stack<int> st;
    for(int i=1;i<=5;i++)
      st.push(i);
      
    int x;
    cin>>x;
    
    insertAtBottom(st, x);
    
    while(!st.empty()) {
        cout << st.top()<<" ";
        st.pop();
    }
      
      return 0;  
}

TC: O(N) ~ To pop all elements out of stack once and then push all elements back ~ Push and pop are O(1) operations but are done N number of times
SC: O(N) for recursion calls, auxillary space is O(1)
