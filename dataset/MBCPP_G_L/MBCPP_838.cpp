int n = s1.length();
int count01 = 0, count10 = 0;
for (int i = 0; i < n; ++i) {
    if (s1[i] != s2[i]) {
        if (s1[i] == '0') count01++;
        else count10++;
    }
}
if ((count01 + count10) % 2 != 0) return -1;
return max(count01, count10);
}