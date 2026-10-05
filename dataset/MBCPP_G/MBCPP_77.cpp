int even_sum = 0, odd_sum = 0;
while (n != 0) {
    int digit = n % 10;
    if (digit % 2 == 0) 
        even_sum += digit;
    else 
        odd_sum += digit;
    n /= 10;
}
return even_sum != odd_sum;
}