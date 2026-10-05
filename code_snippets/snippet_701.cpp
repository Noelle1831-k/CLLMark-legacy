(string::const_iterator first, string::const_iterator last), (find_if(testStr.begin(), testStr.end(), [](char c) { return toupper(c) == c; }))) - testStr.begin() - 1; }
int main() {
  cin.tie(NULL);
  int test=1;
  cin>>test;
  while(test--)
  {
      string s;
      cin>>s;
      cout<<maxRunUppercase(s)<<endl;
  }
  return 0;
}
<|endoftext|>