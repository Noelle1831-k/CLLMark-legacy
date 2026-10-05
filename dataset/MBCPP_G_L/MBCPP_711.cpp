int oddProduct = 1, evenProduct = 1;
bool isOddPosition = true;
while (n > 0) {
    int digit = n % 10;
    if (isOddPosition) {
        oddProduct *= digit;
    } else {
        evenProduct *= digit;
    }
    isOddPosition = !isOddPosition;
    n /= 10;
}
return oddProduct == evenProduct;
}