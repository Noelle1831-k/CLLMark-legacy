int sum_of_divisors = 0;
for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
        while (n % i == 0) {
            n /= i;
        }
        sum_of_divisors += i;
    }
}
if (n > 1) {
    sum_of_divisors += n;
}
return sum_of_divisors;
}