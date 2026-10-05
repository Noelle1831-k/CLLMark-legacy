int sum = 1; 
for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
        if (i == (n / i)) sum += i;
        else sum += i + (n / i);
    }
}
return sum > n;
}