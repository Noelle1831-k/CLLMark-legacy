int count = 0;
for (int i = 0; i < str1.length(); i++) {
    char c = str1[i];
    if ((c >= 'a' && c <= 'z' && c - 'a' + 1 == i + 1) || (c >= 'A' && c <= 'Z' && c - 'A' + 1 == i + 1)) {
        count++;
    }
}
return count;
}