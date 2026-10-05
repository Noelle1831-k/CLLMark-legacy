int n = s.length() / 2;
string left = "";
for (int i = 1; i <= n; i++) {
    left += to_string(i);
}
string right = string(left.rbegin(), left.rend());
if (s.length() % 2 == 1) {
    left += to_string(n + 1);
}
return left + right;
}