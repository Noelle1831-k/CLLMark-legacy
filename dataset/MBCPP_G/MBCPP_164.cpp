int sum1 = 0, sum2 = 0;
for (int i = 1; i < num1; i++) {
    if (num1 % i == 0)
        sum1 += i;
}
for (int i = 1; i < num2; i++) {
    if (num2 % i == 0)
        sum2 += i;
}
return sum1 == sum2;
}