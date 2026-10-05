int sum = 0;
for (int i = 1, count = 0; count < n; i += 2, count++) {
    sum += pow(i, 5);
}
return sum;
}