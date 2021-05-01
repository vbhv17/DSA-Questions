// We Push all opening braces into the stack, and if we find a closing brace in the input string, there should be a corresponding opening brace 
// at the top of the stack for it.

bool ispar(string x)
{
  stack<char> st;
  char temp;

  for (int i = 0; i < x.length(); i++)
  {
    if (x[i] == '(' || x[i] == '{' || x[i] == '[')
    {
      st.push(x[i]);
      continue;
    }


    if (st.empty())                  //here if stack is empty that means we have encountered a clsoing brace before an opening brace that means unbalanced paranthesis
      return false;

    switch (x[i]) {

    case '}':

      temp = st.top();
      st.pop();

      if (temp != '{')
        return false;
      break;

    case ')':

      temp = st.top();
      st.pop();

      if (temp != '(')
        return false;
      break;

    case ']':

      temp = st.top();
      st.pop();

      if (temp != '[')
        return false;
      break;
    }
  }

  return (st.empty());
}

TC: O(N)  SC:O(N)
