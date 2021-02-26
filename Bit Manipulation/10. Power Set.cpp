//Giving an error
//Refer Notes
vector<string> AllPossibleStrings(string s) {

    vector<string> ans;
    int n = s.length();
    int powSize = pow(2, n);

    for (int counter = 0; counter < powSize; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            if (counter & (1 << j))
                ans.push_back(s[j]);
        }
        ans.push_back(" ");
    }
    return ans;
}

TC: Theta(2^n * n)  AS:(1)
