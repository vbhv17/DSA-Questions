https://www.youtube.com/watch?v=8YXQ68oHjAs&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=9&ab_channel=AdityaVermaAdityaVerma

#include<bits/stdc++.h>
using namespace std;

void recInsert(stack<int> &st, int temp)
{
  if (st.size() == 0)
  {
    st.push(temp);
    return;
  }

  int val = st.top();
  st.pop();

  recInsert(st, temp);
  st.push(val);

}
void recReverse(stack<int> &st)
{
  if (st.size() == 0)
    return;

  int temp = st.top();
  st.pop();

  recReverse(st);
  recInsert(st, temp);

}

void printStack(stack<int> st)
{
  if (st.empty())
    return;

  int temp = st.top();
  st.pop();
  printStack(st);
  cout << temp << " ";
  st.push(temp);

}

int main() {

  stack<int> st;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    st.push(data);
  }

  cout << "Before reversing" << endl;
  printStack(st);
  cout << endl;

  recReverse(st);

  cout << "After reversing" << endl;
  printStack(st);

  return 0;
}
