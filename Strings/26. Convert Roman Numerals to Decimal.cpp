https://www.youtube.com/watch?v=KwrAArXFF30&ab_channel=CodeWhoop
int val(char c) {

  switch (c) {

  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  }
}

int romanToDecimal(string &str) {

  int prev = 0, ans = 0;
  int n = str.length() - 1;
  for (int i = n; i >= 0; i--) {

    if (val(str[i]) >= prev) {

      ans = ans + val(str[i]);
    }

    else {
      ans = ans - val(str[i]);
    }

    prev = val(str[i]);
  }

  return ans;
};

TC: O(N)
SC: O(1)
