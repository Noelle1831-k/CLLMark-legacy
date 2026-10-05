int count = 0;
for (int i = 0; i < n; ++i) {
    if ((s.back() - '0') % 2 != 0) {
        count++;
    }
    s = s.substr(1) + s[0];
}
return count;
}