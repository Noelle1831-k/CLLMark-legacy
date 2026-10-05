int sum = 0;
for (char c : strr) {
    sum += c - 'a' + 1;
}
char result = 'a' + (sum - 1) % 26;
return string(1, result);
}