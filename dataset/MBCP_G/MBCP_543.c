int countDigits(long long num1, long long num2) {
    long long sum = num1 + num2;
    int count = 0;
    while (sum != 0) {
        sum /= 10;
        count++;
    }
    return (count == 0) ? 1 : count; 
}