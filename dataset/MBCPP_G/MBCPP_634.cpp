int sum = 0;
for (int i = 1; i <= n; ++i) {
    int evenNum = 2 * i;
    sum += pow(evenNum, 4);
}
return sum;
}