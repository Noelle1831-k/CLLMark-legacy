int n = str.length();
string concat = str + str;
for (int i = 1; i < n; i++) {
    if (concat.substr(i, n) == str) {
        return i;
    }
}
return n;
}