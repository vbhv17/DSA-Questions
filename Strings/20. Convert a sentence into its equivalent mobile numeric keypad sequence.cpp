

string printSequence(string S)
{
    string str[]={ "2", "22", "222", "3", "33", "333", "4", "44", "444", 
                 "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777",
                 "8", "88", "888", "9", "99", "999", "9999"};
              
    string ans= "";
    int n = S.length();        
    for(int i=0; i<n; i++)
    {
        if(S[i] == ' ')
          ans+="0";
    
        else{
          int j = S[i] - 'A';            //this gives the position of the corresponding mobile keypad string from the str array, for the ith character.
          ans += str[j];                 //append this string to ans string
        }
    }
  
  return ans;
}
