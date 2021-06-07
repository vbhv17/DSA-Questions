Solution: Using stack
Algorithm: 

Declare a character stack S.
Now traverse the expression string exp. 
If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack 
and if the popped character is the matching starting bracket then fine else brackets are not balanced.
After complete traversal, if there is some starting bracket left in stack then “not balanced”
  
  
class Solution
{
public:
  //Function to check if brackets are balanced or not.
  bool isBalanced(string x)
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
      
      if (st.empty())
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
};
 
TC:O(N) SC:O(N)
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
