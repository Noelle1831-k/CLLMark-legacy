int n = str.length();
int flip1 = 0, flip2 = 0;
for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
        if (str[i] != '0') flip1++;
        if (str[i] != '1') flip2++;
    } else {
        if (str[i] != '1') flip1++;
        if (str[i] != '0') flip2++;
    }
}
return min(flip1, flip2);
}