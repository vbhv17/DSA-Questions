
class Solution
{
public:
  //Function to evaluate a postfix expression.
  int evaluatePostfix(string S)
  {

    stack<int> st;

    for (int i = 0; i < S.length(); i++)
    {

      if (S[i] >= '0' and S[i] <= '9')           //if the ASCII value of character lies between ASCII of 0 and 9, then it is a number
        st.push(S[i] - '0');                     //converting character to int 

      else
      {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();

        switch (S[i]) {

        case '*':
          st.push(second * first);
          break;

        case '/':
          st.push(second / first);
          break;

        case '+':
          st.push(second + first);
          break;

        case '-':
          st.push(second - first);
          break;

        default:
          break;
        }
      }
    }

    int val =  st.top();
    return val;
  }
};

TC: O(|S|)  //where S is length of input string
SC: O(|S|)

