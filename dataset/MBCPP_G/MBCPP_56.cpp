string s = to_string(n);
reverse(s.begin(), s.end());
int reversedNumber = stoi(s);
return (2 * reversedNumber - 1) == n;
}