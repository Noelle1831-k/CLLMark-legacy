int decimalNumber = 0, base = 1;
while (n > 0) {
    int lastDigit = n % 10;
    n /= 10;
    decimalNumber += lastDigit * base;
    base *= 8;
}
return decimalNumber;
}