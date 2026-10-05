int n = a.size(), length = 0;
while (n > 0 && a[n - 1] == ' ') n--;
while (n > 0 && a[n - 1] != ' ') {
    length++;
    n--;
}
return length;
}