if (n <= 0) return false;
while (n > 0) {
    if (n % 2 == 0) break;
    n -= 2;
}
return n == 0;
}