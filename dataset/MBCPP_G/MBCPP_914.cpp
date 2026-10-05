if (s.length() < 2) return false;
char first = s[0], second = s[1];
if (first == second) return false;
for (int i = 0; i < s.length(); i++) {
    if (i % 2 == 0 && s[i] != first) return false;
    if (i % 2 == 1 && s[i] != second) return false;
}
return true;
}