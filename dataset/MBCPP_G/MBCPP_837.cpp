int sum = 0;
for (int i = 0; i < n; i++) {
    int oddNumber = 2 * i + 1;
    sum += oddNumber * oddNumber * oddNumber;
}
return sum;
}