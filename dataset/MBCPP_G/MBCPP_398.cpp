int totalSum = 0;
for (int num : nums) {
    num = abs(num);
    while (num > 0) {
        totalSum += num % 10;
        num /= 10;
    }
}
return totalSum;
}