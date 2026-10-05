int sum = 0;
for (int i = 0, oddNumber = 1; i < n; ++i, oddNumber += 2) {
    sum += pow(oddNumber, 4);
}
return sum;
}