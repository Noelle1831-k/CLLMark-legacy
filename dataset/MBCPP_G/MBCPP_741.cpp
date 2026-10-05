if (s.empty()) return true;
char firstChar = s[0];
for (char ch : s) {
    if (ch != firstChar) return false;
}
return true;
}